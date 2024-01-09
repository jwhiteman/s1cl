(import
  (only regex string-split-fields)
  (only (chicken bitwise) bitwise-xor))

(define input "1c0111001f010100061a024b53535009181c")
(define key "686974207468652062756c6c277320657965")

(define (hex-list hex-string)
  (string-split-fields ".." hex-string))

(define (fixed-xor input key)
  (map (lambda (l r)
         (number->string
           (bitwise-xor (string->number l 16)
                        (string->number r 16))
           16))
       (hex-list input)
       (hex-list key)))

(print (apply string-append (fixed-xor input key)))
;; "746865206b696420646f6e277420706c6179"
