(define/contract (reverse x)
  (-> exact-integer? exact-integer?)
    (define (rev x target)
      (if (= x 0) target
        (* (sgn x) (rev (quotient (abs x) 10) (+ (* target 10) (remainder (abs x) 10))))))
    (define (overflow? x) (or (< x (- (expt 2 31))) (> x (- (expt 2 31) 1))))

    (define ans (rev x 0))
    (if (overflow? ans) 0 ans)
  )