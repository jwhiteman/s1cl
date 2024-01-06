(foreign-declare "#include \"decodehex.h\"")

(define free
  (foreign-lambda void "free" c-pointer))

;; leads to "pointer being freed was not allocated" error
;; is it possible that it gets free'd immediately?
(define free-string
  (foreign-lambda void "free" c-string*))

(define decodehex
  (foreign-lambda
    c-string
    "decode_hex_string"
    c-string))


;; (free-string (decodehex "515151"))

(let ((result (decodehex "697420776f726b73")))
  (print result))
