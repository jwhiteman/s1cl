(import (chicken platform) srfi-18) ;; Needs the srfi-18 egg

(define m (make-mutex))

(define (t)
  (mutex-lock! m)
  (thread-sleep! 1)
  (print (thread-name (current-thread)))
  (mutex-unlock! m)
  (t) )

(thread-start! (make-thread t 'PING!))
(thread-start! (make-thread t 'PONG!))

(let loop ()
  (return-to-host)
  (thread-yield!)
  (loop) )
