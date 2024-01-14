(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor)
  (only format format)
  (chicken platform)
  (chicken foreign))

(define (hex-list hex-string)
  (string-split-fields ".." hex-string))

(define (fixed-xor input key)
  (map (lambda (l r)
         (bitwise-xor (string->number l 16)
                      (string->number r 16)))
       (hex-list input)
       (hex-list key)))

(define-external
  (fixedxor (c-string input) (c-string key)) c-string
  (format "~{~x~}" (fixed-xor input key)))

(return-to-host)
