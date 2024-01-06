(defconstant input (concatenate 'string "Burning 'em, if you ain't quick and "
                                "nimble\nI go crazy when I hear a cymbal"))

(defconstant the-key "ICE")

(defun to-bytes (str)
  (map 'list #'char-code str))

(defun repeating-key (master-key)
  (let ((key-copy master-key))
    (lambda ()
      (prog1
        (car key-copy)
        (let ((key-copy-rest (cdr key-copy)))
          (if (null key-copy-rest)
            (setf key-copy master-key)
            (setf key-copy key-copy-rest)))))))

(defun decrypt (text key)
  (let* ((input-bytes (to-bytes text))
         (key-bytes (to-bytes key))
         (key-f (repeating-key key-bytes)))
    (format nil "~(~{~2,'0x~}~)"
            (mapcar #'(lambda (input-byte)
                        (logxor input-byte (funcall key-f)))
                    input-bytes))))

(format t "~a~%" (decrypt input the-key))
