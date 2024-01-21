(ql:quickload :cl-base64)

(defun to-bytes (str)
  (map 'list #'char-code str))

(defconstant input-bytes
             (with-open-file (instream "6.txt")
               (to-bytes
                 (cl-base64:base64-stream-to-string instream))))

(defun byte-distance (byte1 byte2)
  (labels ((accumulate (xor-result idx num-diff-bits)
                       (if (zerop idx)
                         num-diff-bits
                         (accumulate (ash xor-result -1)
                                     (1- idx)
                                     (+ num-diff-bits (logand xor-result 1))))))
    (accumulate (logxor byte1 byte2) 8 0)))

(defun hamming-distance (str1 str2)
  (labels ((accumulate (bytes1 bytes2 count)
                       (if (null bytes1)
                         count
                         (accumulate (cdr bytes1)
                                     (cdr bytes2)
                                     (+ count (byte-distance (car bytes1)
                                                             (car bytes2)))))))
    (accumulate (to-bytes str1) (to-bytes str2) 0)))
