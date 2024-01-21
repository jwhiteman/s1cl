(ql:quickload :cl-base64)

(defun to-bytes (str)
  (map 'vector #'char-code str))

(defconstant input-bytes
             (with-open-file (instream "6.txt")
               (to-bytes
                 (cl-base64:base64-stream-to-string instream))))

;; meh...the c is actually nicer for this type of style
(defun hamming-distance (str1 str2)
  (let* ((bytes1 (to-bytes str1))
         (bytes2 (to-bytes str2))
         (len (length bytes1))
         (count 0))
    (do ((idx 0 (1+ idx)))
      ((= idx len) count)
      (let ((xor (logxor (aref bytes1 idx)
                         (aref bytes2 idx))))
        (do ((bidx 0 (1+ bidx)))
          ((= bidx 8))
          (setf count (+ count (logand xor 1))
                xor (ash xor -1)))))))

(hamming-distance "this is a test" "wokka wokka!!!")
