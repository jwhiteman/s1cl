(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor)
  (only format format))

(define input "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736")

(define (score str)
  (length (string-split-fields "(?i)[etaoin shrdlu]" str)))

(define (score-char-list char-list)
  (score (list->string char-list)))

(define (to-int hex-byte-str)
  (string->number hex-byte-str 16))

(define key-builder
  (lambda (i)
    (lambda (byte)
      (bitwise-xor byte i))))

(define (hex-to-bytes key hex-str)
  (map (compose integer->char key to-int)
       (string-split-fields ".." hex-str)))

(let ((max-key '())(max-score 0))
  (do ((i 0 (+ i 1)))
    ((> i 255))
    (let* ((key (key-builder i))
           (current-score
            (score-char-list
              (hex-to-bytes key input))))
      (if (> current-score max-score)
        (begin
          (set! max-score current-score)
          (set! max-key i)))))
  (format #t "~a~%" (list->string
                      (hex-to-bytes (lambda (byte)
                                      (bitwise-xor byte max-key))
                                    input))))
