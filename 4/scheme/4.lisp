(load "~/quicklisp/setup.lisp")

(ql:quickload :cl-ppcre)

(defun score (str)
  (length
    (cl-ppcre:all-matches-as-strings "(?i)[etaoin shrldu]" str)))

(defun decrypt (hexstr key)
  (format nil "~{~A~}"
          (mapcar #'(lambda (h)
                      (code-char
                        (logxor (parse-integer h :radix 16)
                                key)))
                  (cl-ppcre:all-matches-as-strings ".." hexstr))))

(let ((max 0)
      (msg))
  (with-open-file (instream "4.txt" :direction :input)
    (do ((line (read-line instream nil :eof)
               (read-line instream nil :eof)))
      ((eql line :eof) (format t "~A~%" msg))
      (do ((key 0 (1+ key)))
        ((> key 127))
        (let* ((res (decrypt line key))
               (score (score res)))
          (when (> score max)
            (setf max score
                  msg res)))))))

;; > "Now that the party is jumping"
