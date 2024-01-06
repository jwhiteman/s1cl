(foreign-declare "#include \"myadd.h\"")

(define myadd
  (foreign-lambda
    int
    "myadd"
    int))

(print (myadd 68))
