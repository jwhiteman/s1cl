;; chicken-install format => http://wiki.call-cc.org/eggref/5/format
;; note: (chicken format) and srfi-28 both implement "format" functions

(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor)
  (only format format))

(define input "1c0111001f010100061a024b53535009181c")
(define key "686974207468652062756c6c277320657965")

(define (hex-list hex-string)
  (string-split-fields ".." hex-string))

(define (fixed-xor input key)
  (map (lambda (l r)
         (bitwise-xor (string->number l 16)
                      (string->number r 16)))
       (hex-list input)
       (hex-list key)))

(print (format "~{~x~}" (fixed-xor input key)))
;; "746865206b696420646f6e277420706c6179"
