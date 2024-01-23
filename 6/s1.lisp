(defun in-slices (lst-f lst k)
  (labels ((F (lst idx slice-1 slice-2)
              (cond ((null lst)
                     (when (= (length slice-2) k)
                       (funcall lst-f slice-1 (reverse slice-2))))
                    ((= idx k)
                     (let ((cur (reverse slice-2)))
                       (when slice-1
                         (funcall lst-f slice-1 cur))
                       (F lst 0 cur '())))
                    (t
                      (F (cdr lst)
                         (1+ idx)
                         slice-1
                         (cons (car lst) slice-2))))))
    (F lst 0 '() '())))

(defun average-hamming-distance (input k)
  (let ((acc))
    (in-slices #'(lambda (bytes1 bytes2)
                   (let ((nhd (normalized-hamming-distance bytes1 bytes2)))
                     (setf acc (cons nhd acc))))
               input
               k)
    (/ (reduce #'+ acc) (length acc))))

(defun most-likely-keysize (input)
  (let ((acc))
    (do ((keysize 2 (1+ keysize)))
      ((> keysize 40) (caar (sort acc #'< :key #'cdr)))
      (let ((entry (cons keysize (ahd input keysize))))
        (setf acc (cons entry acc))))))

(mlks input-bytes)


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
