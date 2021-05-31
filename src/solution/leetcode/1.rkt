(define/contract (two-sum nums target)
  (-> (listof exact-integer?) exact-integer? (listof exact-integer?))
    (define vis (make-hash))
    (define run (lambda (idx) 
      (define diff (- target (list-ref nums idx)))
      (cond 
        [(hash-ref vis diff #f) (list (hash-ref vis diff) idx)]
        [else (hash-set! vis (list-ref nums idx) idx) (run (+ idx 1))])
    ))
    (run 0)
  )