(import (only format format))

(foreign-declare "#include \"2.h\"")

(define free (foreign-lambda void "free" c-string))

(define fixed-xor
  (foreign-lambda
    c-string
    "fixed_xor"
    c-string
    c-string))

(let ((result (fixed-xor "1c0111001f010100061a024b53535009181c"
                         "686974207468652062756c6c277320657965")))
  (format #t "The result is ~a~%" result))
