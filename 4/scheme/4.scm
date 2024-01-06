(import (only (chicken io) read-line)
        (only regex string-split-fields)
        (only (chicken bitwise) bitwise-xor)
        matchable)

(define-syntax λ
  (syntax-rules ()
    ((_ (args ...) body ...)
     (lambda (args ...) body ...))))

(define (each-line line-f file)
  (call-with-input-file file
                        (λ (in)
                          (let loop ((line (read-line in))
                                     (line-number 0))
                            (when (not (eof-object? line))
                              (begin
                                (line-f line line-number)
                                (loop (read-line in)
                                      (add1 line-number))))))))

(define (score plaintext)
  (length
    (string-split-fields "(?i)[etaoin shrdlu]" plaintext)))

(define (decrypt hexstr key-byte)
  (list->string
    (map (compose integer->char
                  (λ (hexint) (bitwise-xor hexint key-byte))
                  (λ (hexbyte) (string->number hexbyte 16)))
         (string-split-fields ".." hexstr))))

(define (crack input)
  (let ((max-score 0)
        (msg '()))
    (do ((i 0 (add1 i)))
      ((> i 127) (list max-score msg))
      (let* ((plaintext (decrypt input i))
             (current-score (score plaintext)))
        (when (> current-score max-score)
          (set! max-score current-score)
          (set! msg plaintext))))))

(let ((max-score 0)
      (msg '())
      (msg-idx -1))
  (each-line (λ (line line-number)
               (match-let (((best-score potential-msg) (crack line)))
                          (when (> best-score max-score)
                            (set! max-score best-score)
                            (set! msg potential-msg)
                            (set! msg-idx line-number))))
             "4.txt")
  (display msg))
