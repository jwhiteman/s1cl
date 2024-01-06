(define distance
  (foreign-lambda* double
                   ((double x)
                    (double y))
                   "double res;"
                   "res = sqrt(x * x + y * y);"
                   "C_return (res);"))

(print (distance 3 4))
