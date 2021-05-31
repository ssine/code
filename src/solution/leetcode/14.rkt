(define/contract (longest-common-prefix strs)
  (-> (listof string?) string?)
    (cond
      [(= (length strs) 0) ""]
      [(ormap (lambda (x) (= (string-length x) 0)) strs) ""]
      [(andmap (lambda (c) (eq? c (string-ref (car strs) 0))) (map (lambda (s) (string-ref s 0)) strs))
        (string-append (substring (car strs) 0 1) (longest-common-prefix (map (lambda (s) (substring s 1)) strs)))]
      [else ""])
  )