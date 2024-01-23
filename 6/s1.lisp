(defun in-slices (lst-f lst k)
  (labels ((H (lst idx slice-1 slice-2)
              (cond ((null lst)
                     (when (= (length slice-2) k)
                       (funcall lst-f slice-1 (reverse slice-2))))
                    ((= idx k)
                     (let ((cur (reverse slice-2)))
                       (when slice-1
                         (funcall lst-f slice-1 cur))
                       (H lst 0 cur '())))
                    (t
                      (H (cdr lst)
                         (1+ idx)
                         slice-1
                         (cons (car lst) slice-2))))))
    (H lst 0 '() '())))


(in-slices #'(lambda (a b)
               (format t "~a ~a~%" a b))
           '(1 2 3 4 5 6 7 8 9)
           3)

(in-slices #'(lambda (a b)
               (format t "~a ~a~%" a b))
           '(1 2 3 4 5 6 7 8 9)
           4)

(in-slices #'(lambda (a b)
               (format t "~a ~a~%" a b))
           '(1 2 3 4 5 6 7 8 9)
           5)
