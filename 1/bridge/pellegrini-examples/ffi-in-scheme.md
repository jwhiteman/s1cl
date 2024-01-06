# Interface Chicken Scheme ↔ C
by Jeronimo C. Pellegrini

## 1 FFI

It is very common for compilers and interpreters to offer the user some mechanism
that allows routines written in other languages to be integrated into the same program.
This way it is possible to build programs in Scheme, for example, that use functions
C or C++ (and as you can normally also make calls from C to other
languages, the possibility of using several programming languages in one
It’s just the program.
In the discussion that follows the scenario is a Scheme program using C functions, but
it must be understood that the concepts are valid for other languages as well.

## 1.1 Callbacks

When a Scheme program calls a C function, and this function in turn calls
another Scheme function, this last call is called callback.

The problem with callbacks is that different languages can handle the callback stack in
very different ways, and this must be taken into account by those who implement
the FFI mechanism.

## 2 FFI in Chicken Scheme

The Chicken Scheme compiler translates Scheme programs into C, and then calls
a common C compiler to generate binary code. It is natural then that there are ways
of including, within the Scheme code, calls to C functions (and even snippets of C code).

The basic Chicken Scheme mechanism for interfacing with C only works, therefore,
in compiled code (and not in the interpreter). To use FFI from the interpreter
there is the lazy-ffi module, described in section 5.

NOTE:

There is an analogy to a practice for making telephone calls, when one person calls another
and asks the other to “call back” – the name given in English to this practice is callback, and at one time there was
companies that offered a specialized callback service to make calls cheaper (such as a call from
country A to country B is more expensive than from country B to country A, the company offered the possibility for citizens
from country A to request a callback from country B, but in a transparent way for its interlocutor.

The simplest way to call C functions in Chicken Scheme programs is using
the foreign-code macro:

```
(foreign-code "puts(\" Hello ’!\");"
              "puts(\"Good morning!\");")
```


Note the escaped quotes within the string and the semicolon after the C command.


## 3 Calling C functions

Although foreign-code is useful for executing simple C code, it is inconvenient when
if you want to call a C function as if it were a Scheme procedure. For situations
like this, foreign-lambda defines a Scheme procedure as similar as possible
to a given function C:

```
(define sine (foreign-lambda double sin double))
(display (sine 3.1415926536))
```

The arguments to foreign-lambda are the type of the value returned by the C function
followed by the types of the parameters.
Of course, if the function will be called once, you can dispense with the define:

```
(display ((foreign-lambda double sin double) 3.1415926536))
```

However, foreign-lambda only works for C functions that do not make callbacks.

Calling a single C function is not always convenient; sometimes it is
It is necessary to insert a small piece of code into the Scheme program. This can be done
with the foreign-lambda* macro:

```
(defines distance
         (foreign-lambda*()
           ((double x)
            (double y))
           " double res ; "
           " res = sqrt ( x * x + y * y ); "
           " C_return ( res ); " ))
```

Note that the C snippet returns a value, but uses `C_return` (and not the common return
of C). This is necessary because of the way Chicken Scheme compiles programs
(the `C_return` function needs to do some “administrative cleanup” before returning the value).

## 3.1 External variables

There is a difference between defining a variable (the definition determines when, how, and what
type of variable is created, and can only exist in a single place) and declare a variable
(the declaration just tells the compiler or interpreter that the variable exists – and
possibly also informs its type).

When mixing Scheme and C, it is important to keep in mind that each variable must be
defined in a single point, which can be in the Scheme part or in the C part of the program
(but not in both) – but when defined in one of the sides, it must be declared in the

another so that it is visible there.

```
(define-foreign-variable NAME TYPE [ STRING ])
```

The define-foreign-variable macro links the scheme NAME symbol to the C STRING expression
type TYPE. If the C expression is an identifier, it will be possible to use set! in NAME to
assign value to variable C.
Note that the following program:

```
(define-foreign-variable x double " var_x ")
(printx)
```

doesn't work, because define-foreign-variable only determines that the symbol
Scheme x must be translated into the C variable `var_x` – and does not define `var_x`.

## 3.2 Callbacks

This section deals with the situation in which Scheme procedures call a C function that
calls a Scheme callback procedure again.

## 3.2.1 Scheme → C → Scheme

It may be necessary to write a Scheme procedure to call a C function that in turn
once again calls Scheme procedures:

Procedure X (Scheme) -> function Y (C) -> procedure Z (Scheme)

The first Scheme procedure (X in the figure) must be done with foreign-safe-lambda
and foreign-safe-lambda* instead of foreign-lambda. “safe” means that this procedure
will do some “tidying up” on the stack before returning (this is necessary in this
case).

## 3.2.2 Defining callback procedures

To define Scheme procedures visible from C, use the define-external macro:

```
(define-external [ QUALIFIERS ]
(NAME (ARGUMENTTYPE1 VARIABLE1) ...) RETURNTYPE
BODY ...)
```

For example:

```
(define-external (foo (c-string x)) int (string-length x))
```

## 3.2.3 Accessing Scheme variables from C

```
(define-external x double 0.5)
  (print x)
  ((foreign-lambda* int ()
    "C_return (x);"))

;; == > 0.5
```

because define-external defines a variable x, and also declares it in part C of
program. Its general form is:

```
(define-external NAME TYPE [ INIT ])
```

## 4 Embedding Scheme in C programs

This section deals with when you want to use Scheme procedures in a C program (whose
entry point is in C, and therefore started the C runtime, not the Chicken Scheme runtime).
To embed Scheme in C, you need:

- Use the chicken.h header file;
- Include a header file with the definitions of the exported Scheme functions for C;
- Call `CHICKEN_run(C_toplevel)` before calling the Scheme functions.

For example, a multiply-in-scheme function, made in Scheme, can be used
from C. To do this, you must declare it in the Scheme program with define-external:

```
(import foreign)

(define-external
  (multiplica_em_scheme (int x)
                        (int y)) int
    (* x y))

(return-to-host)
```

The return-to-host call is important: the `CHICKEN_run` function transfers the con-
switch from program C to Chicken, and control only returns to program C when
return-to-host is called.

In minhas-funcoes.h:

```
extern int multiplica_em_scheme (int a, int b);
```

In the C program:

```
#include <chicken.h>
#include "minhas-funcoes.h"

int main() {
  C_word result;
  CHICKEN_run(C_toplevel);
  CHICKEN_eval_string("(begin (display ’hello) (newline))", &result);
  printf("%d\n", multiplica_em_scheme(5,4));
}
```

The Chicken compiler, csc, can be used to compile both files:

```
csc -C -I. programa-scheme.scm programa-c.c -e
```

The -e option instructs the compiler not to generate the main function, which
 already exists in the C program.

**Important**: csc will generate a file with the same name as the Scheme file, but
changing the extension to .c – therefore the names of Scheme and programs must be
different. Consider the following:

```
csc -C -I. prog.scm prog.c -e
```

It won't work and you will lose your prog.c program, which will be overwritten
by the translation from prog.scm to C.
There are other functions for the C ↔ Scheme interface, all documented in the manual
Chicken Scheme.

## 5 FFI in uncompiled code: lazy-FFI

The facilities exposed so far allow interface between C and Scheme for code
compiled. This is simple because the compiler only needs to include the code snippets
and function calls in an intermediate file before compiling the executable. A
interpreter does not compile, therefore the use of external calls must be done in a
different manner.

The lazy-ffi module allows you to load dynamic shared libraries.
App will load lazy-ffi with (require-extension lazy-ffi), use

```
#~"libwhatever.so"
```

To load the libwhatever C library.

To use the library functions, use #~SYMBOL to use the C function with the same
name that SYMBOL (the value of #~SYMBOL in Scheme will be a procedure that calls
the C function of the same name).

```
#;1> (use lazy-ffi)
  ...
#;2> #~"libc.so.6"
(libc.so.6)
#;3> (#~puts "Uma string")
Uma string
#;4>
```

Arguments are automatically converted from Scheme types to C types.
according to the following table:

```
boolean        int (1 or 0)
exact          int
inexact        double
char           char

pointer/
locative       void *

string         char *
symbol         char *
```

The #~SYMBOL procedure, however, does not return a value. So that he can do it, and
It is necessary to inform the type of the value using the “return:” token:

```
(#~sin 0.1 return: double:)
0.0998334166468282
```

The possible return values are:

```
int: char: float: double: pointer:
string: symbol: bool: void: scheme-object:
```

Procedures generated with #~ cannot callback to Scheme code, unless
unless the safe parameter is passed to them: #t.
