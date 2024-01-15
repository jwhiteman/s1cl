(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor))

(define input "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736")

(define (score str)
  (length (string-split-fields "(?i)[etaoin shrdlu]" str)))

(define (decrypt key hex-str)
  (list->string
    (map (compose integer->char
                  (lambda (hex-int) (bitwise-xor hex-int key))
                  (lambda (hex-byte) (string->number hex-byte 16)))
         (string-split-fields ".." hex-str))))

(let ((max-score 0)
      (msg "failed."))
  (do ((i 0 (+ i 1)))
    ((> i 255) (print msg))
    (let* ((res (decrypt i input))
           (current-score (score res)))
      (when (> current-score max-score)
        (set! max-score current-score)
        (set! msg res)))))
;; Cooking MC's like a pound of bacon
