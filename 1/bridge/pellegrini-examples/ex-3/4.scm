(define my-strlen
  (foreign-lambda* int ((c-string str))
    "int n = 0;
     while(*(str++)) ++n;
     C_return(n);") )

(print (my-strlen "one two three"))
