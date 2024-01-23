(ql:quickload :cl-base64)

(defun to-bytes (str)
  (map 'list #'char-code str))

(defconstant input-bytes
             (with-open-file (instream "6.txt")
               (to-bytes
                 (cl-base64:base64-stream-to-string instream))))

(defun byte-distance (byte1 byte2)
  (labels ((H (xor-result idx num-diff-bits)
              (if (zerop idx)
                num-diff-bits
                (H (ash xor-result -1)
                   (1- idx)
                   (+ num-diff-bits (logand xor-result 1))))))
    (H (logxor byte1 byte2) 8 0)))

(defun hamming-distance (bytes1 bytes2)
  (labels ((H (bytes1 bytes2 count)
              (if (null bytes1)
                count
                (H (cdr bytes1)
                   (cdr bytes2)
                   (+ count (byte-distance (car bytes1)
                                           (car bytes2)))))))
    (H bytes1 bytes2 0)))

(defun normalized-hamming-distance (bytes1 bytes2)
  (/ (hamming-distance bytes1 bytes2)
     (length bytes1)))

(defun in-slices (lst-f lst k)
  (labels ((F (lst idx slice-1 slice-2 acc)
              (cond ((null lst)
                     (if (= (length slice-2) k)
                       (funcall lst-f slice-1 (reverse slice-2) acc)
                       acc))
                    ((= idx k)
                     (let ((cur (reverse slice-2)))
                       (F lst                                 ;; list
                          0                                   ;; idx
                          cur                                 ;; slice-1
                          '()                                 ;; slice-2
                          (funcall lst-f slice-1 cur acc))))  ;; acc
                    (t
                      (F (cdr lst)                            ;; list
                         (1+ idx)                             ;; idx
                         slice-1                              ;; slice-1
                         (cons (car lst) slice-2)             ;; slice-2
                         acc)))))                             ;; acc
    (F lst 0 '() '() '())))

(defun average-hamming-distance (input k)
  (let ((res (in-slices #'(lambda (bytes1 bytes2 acc)
                            (if (and bytes1 bytes2)
                              (let ((nhd (normalized-hamming-distance bytes1 bytes2)))
                                (cons nhd acc))
                              acc))
                        input
                        k)))
             (/ (reduce #'+ res) (length res))))

(defun most-likely-keysize (input)
  (let ((acc))
    (do ((keysize 2 (1+ keysize)))
      ((> keysize 40) (caar (sort acc #'< :key #'cdr)))
      (let* ((ahd (average-hamming-distance input keysize))
             (entry (cons keysize ahd)))
        (setf acc (cons entry acc))))))

(defun most-likely-keysize (input from to)
  (labels ((F (from acc)
              (if (> from to)
                acc
                (let ((ahd (average-hamming-distance input from)))
                  (F (1+ from)
                     (cons (cons from ahd) acc))))))
    (caar (sort (F from '()) #'< :key #'cdr))))
