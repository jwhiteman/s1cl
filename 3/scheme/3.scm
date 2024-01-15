(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor))

(define input "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736")

(define (score str)
  (length (string-split-fields "(?i)[etaoin shrdlu]" str)))

(define (hex->integer hex-byte-str)
  (string->number hex-byte-str 16))

(define key-builder
  (lambda (i)
    (lambda (byte)
      (bitwise-xor byte i))))

(define (decrypt key-f hex-str)
  (list->string
    (map (compose integer->char
                  key-f
                  hex->integer)
         (string-split-fields ".." hex-str))))

(let ((max-score 0)
      (msg "failed."))
  (do ((i 0 (+ i 1)))
    ((> i 255) (print msg))
    (let* ((key-f (key-builder i))
           (res (decrypt key-f input))
           (current-score (score res)))
      (when (> current-score max-score)
        (set! max-score current-score)
        (set! msg res)))))
;; Cooking MC's like a pound of bacon
