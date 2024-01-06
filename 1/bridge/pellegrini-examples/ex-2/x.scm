(import (chicken platform) (chicken foreign))

(define-external
  (multiplica_em_scheme (int x)
                        (int y)) int
  (begin
    (print "made it mofo!")
    (* x y)))

(return-to-host)
