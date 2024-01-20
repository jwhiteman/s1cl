(defconstant verse (concatenate 'string "Burning 'em, if you ain't quick and "
                                "nimble\nI go crazy when I hear a cymbal"))

(defconstant ice "ICE")

(defun to-bytes (str)
  (map 'list #'char-code str))

(defun key-f (keyb)
  (let ((keyb2 keyb))
    (lambda ()
      (prog1
        (car keyb2)
        (let ((next (cdr keyb2)))
          (if (null next)
            (setf keyb2 keyb)
            (setf keyb2 next)))))))

(defun repeat-key-xor (input key)
  (let* ((ibytes (to-bytes input))
         (kbytes (to-bytes key))
         (key-fun (key-f kbytes)))
    (format nil "~(~{~2,'0x~}~)"
            (mapcar #'(lambda (ibyte)
                        (logxor ibyte (funcall key-fun)))
                    ibytes))))

(format t "~a~%" (repeat-key-xor verse ice))
