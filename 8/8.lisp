(ql:quickload :cl-ppcre)

(defun detect-duplicate-blocks (line idx)
  (reduce #'(lambda (table block)
              (progn
                (if (gethash block table)
                  (format t "multiple blocks detected! line ~a~%" idx)
                  (setf (gethash block table) 1))
                table))
          (cl-ppcre:all-matches-as-strings ".{32}" line)
          :initial-value (make-hash-table :test #'equal)))

(with-open-file (instream "8.txt" :direction :input)
  (do ((line (read-line instream nil 'eof)
             (read-line instream nil 'eof))
       (idx 1 (1+ idx)))
    ((eql line 'eof) 'done)
    (detect-duplicate-blocks line idx)))

;; multiple blocks detected! line 133...
