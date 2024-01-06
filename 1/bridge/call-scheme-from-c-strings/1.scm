(import
  (only regex string-split-fields)
  (chicken platform)
  (chicken foreign))

(define (hex-to-char hex-byte)
  (integer->char
    (string->number hex-byte 16)))

(define-external
  (decodehex (c-string hexstring)) c-string
  (list->string
    (map hex-to-char (string-split-fields ".." hexstring))))

(return-to-host)
