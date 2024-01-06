(ql:quickload :cl-ppcre)
(ql:quickload :cl-base64)

(defconstant input (concatenate 'string "49276d206b696c6c696e6720796f75722062"
                                        "7261696e206c696b65206120706f69736f6e"
                                        "6f7573206d757368726f6f6d"))

(defun decode-hex (hex)
  (format nil "~{~a~}"
          (mapcar #'(lambda (hbyte)
                      (code-char (parse-integer hbyte :radix 16)))
                  (cl-ppcre:all-matches-as-strings ".." hex))))

(let ((res (decode-hex input)))
  (cl-base64:string-to-base64-string res))
