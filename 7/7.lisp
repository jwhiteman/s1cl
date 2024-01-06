(ql:quickload :cl-base64)
(ql:quickload :ironclad)

(defvar key "YELLOW SUBMARINE")

(defun get-cipher (key)
  (ironclad:make-cipher :aes
                        :mode :ecb
                        :key (ironclad:ascii-string-to-byte-array key)))

(defun decrypt (ciphertext key)
  (let ((cipher (get-cipher key))
        (msg (ironclad:ascii-string-to-byte-array ciphertext)))
    (ironclad:decrypt-in-place cipher msg)
    (map 'string #'code-char msg)))

(with-open-file (instream "7.txt")
  (let* ((bytes (cl-base64:base64-stream-to-string instream))
         (msg (decrypt bytes key)))
    (format t "~a~%" msg)))
