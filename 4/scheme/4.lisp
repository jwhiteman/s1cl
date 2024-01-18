(load "~/quicklisp/setup.lisp")

(ql:quickload :cl-ppcre)

(defun compose (&rest fns)
  (destructuring-bind (fn1 . rest) (reverse fns)
    #'(lambda (&rest args)
        (reduce #'(lambda (v f) (funcall f v))
                    rest
                    :initial-value (apply fn1 args)))))

(defun score (str)
  (length
    (cl-ppcre:all-matches-as-strings "(?i)[etaoin shrldu]" str)))

(defun decrypt (hexstr key)
  (format nil "~{~A~}"
          (mapcar (compose #'code-char
                           #'(lambda (b) (logxor b key))
                           #'(lambda (h) (parse-integer h :radix 16)))
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
