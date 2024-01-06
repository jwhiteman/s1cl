(define-library (mytime)
  (export mytime)
  (import (scheme base) (chicken foreign))
  (begin
    (define mytime
      (foreign-lambda* unsigned-long ()
       "C_return(time(NULL));"))))
