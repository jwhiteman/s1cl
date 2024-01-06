(foreign-declare "#include \"myadd.h\"")

(define myadd
  (foreign-lambda
    c-string
    "myadd"
    c-string))

;; note: if there are no args, for example, just leave them off:
;; (foreign-lambda c-string "myadd")

(print (myadd "dingbat"))
