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

(defun in-blocks (input block-length num-blocks)
  (labels ((H (idx acc)
              (if (= idx num-blocks)
                (reverse acc)
                (H (1+ idx)
                   (cons (subseq input (* block-length idx)
                                 (* block-length (1+ idx)))
                         acc)))))
    (H 0 '())))

(defun avg-hamming-distance (blocks)
  (labels ((H (prev lob idx acc)
              (if (null lob)
                (/ (reduce #'+ acc) idx)
                (let* ((cur (car lob))
                       (hd (normalized-hamming-distance prev cur)))
                  (H cur
                     (cdr lob)
                     (1+ idx)
                     (cons hd acc))))))
    (H (car blocks) (cdr blocks) 0 '())))

(defun min-sort (res)
  (sort res #'(lambda (a b) (< (cdr a) (cdr b)))))

(let ((acc))
  (do ((i 2 (1+ i)))
    ((> i 40) (min-sort acc))
    (let ((res
            (avg-hamming-distance (in-blocks input-bytes i 12))))
      (setf acc
            (cons (cons i res) acc)))))
