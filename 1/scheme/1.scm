(import
  (only regex string-split-fields)
  (only (chicken string) conc)
  (only base64 base64-encode))

(define HEX (conc "49276d206b696c6c696e6720796f757220627261696e206c696b652"
                  "06120706f69736f6e6f7573206d757368726f6f6d"))

(define (hex-to-char hex-byte)
  (integer->char
    (string->number hex-byte 16)))

(define (decode-hex hex-string)
  (list->string
    (map hex-to-char (string-split-fields ".." HEX))))

(let ((res (base64-encode (decode-hex HEX))))
  (print res))

;; => "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"
