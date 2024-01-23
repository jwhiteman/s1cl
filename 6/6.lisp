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
  (labels ((_ (&key lst idx slice-1 slice-2 acc)
              (cond ((null lst)
                     (if (= (length slice-2) k)
                       (funcall lst-f slice-1 (reverse slice-2) acc)
                       acc))
                    ((= idx k)
                     (let ((cur (reverse slice-2)))
                       (_ :lst lst
                          :idx 0
                          :slice-1 cur
                          :slice-2 '()
                          :acc (funcall lst-f slice-1 cur acc))))
                    (t
                      (_ :lst (cdr lst)
                         :idx (1+ idx)
                         :slice-1 slice-1
                         :slice-2 (cons (car lst) slice-2)
                         :acc acc)))))
    (_ :lst lst :idx 0 :slice-1 '() :slice-2 '() :idx '())))

(defun accumulate-hamming-distances (bytes1 bytes2 acc)
  (if (and bytes1 bytes2)
    (cons (normalized-hamming-distance bytes1 bytes2) acc)
    acc))

(defun average-hamming-distance (input keysize)
  (let ((hamming-distances (in-slices #'accumulate-hamming-distances
                                      input
                                      keysize)))
    (/ (reduce #'+ hamming-distances)
       (length hamming-distances))))

(defun most-likely-keysize (input &key from-keysize to-keysize)
  (labels ((_ (from-keysize acc)
              (if (> from-keysize to-keysize)
                acc
                (let ((ahd (average-hamming-distance input from-keysize)))
                  (_ (1+ from-keysize)
                     (cons (cons from-keysize ahd) acc))))))
    (caar (sort (_ from-keysize '()) #'< :key #'cdr))))

;; (most-likely-keysize input-bytes :from-keysize 2 :to-keysize 40)
