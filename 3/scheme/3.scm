(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor))

(define input "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736")

(define (score str)
  (length (string-split-fields "(?i)[etaoin shrdlu]" str)))

(define (to-int hex-byte-str)
  (string->number hex-byte-str 16))

(define key-builder
  (lambda (i)
    (lambda (byte)
      (bitwise-xor byte i))))

(define (decrypt key-f hex-str)
  (list->string
    (map (compose integer->char key-f to-int)
         (string-split-fields ".." hex-str))))

(let ((max-key '())(max-score 0)(max-message "failed."))
  (do ((key-byte 0 (+ key-byte 1)))
    ((> key-byte 255) (print max-message))
    (let* ((key-f (key-builder key-byte))
           (decrypted-text (decrypt key-f input))
           (current-score (score decrypted-text)))
      (if (> current-score max-score)
        (begin
          (set! max-score current-score)
          (set! max-key key-byte)
          (set! max-message decrypted-text))))))
;; Cooking MC's like a pound of bacon
