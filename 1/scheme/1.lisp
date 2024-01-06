(ql:quickload :cl-ppcre)
(ql:quickload :cl-base64)

(defconstant input (concatenate 'string
                                "49276d206b696c6c696e6720796f757220627261696e2"
                                "06c696b65206120706f69736f6e6f7573206d757368726"
                                "f6f6d"))

(defun decode-hex (hex)
  (format nil "~{~a~}"
          (mapcar #'(lambda (hbyte)
                      (code-char (parse-integer hbyte :radix 16)))
                  (cl-ppcre:all-matches-as-strings ".." hex))))

(let ((decoded (decode-hex input)))
  (cl-base64:string-to-base64-string decoded))
; "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"
