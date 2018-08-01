(define (rember a lat)
  (cond
   ((null? lat) lat)
   ((eq? a (car lat)) (cdr lat))
   (else (cons (car lat)
               (rember a (cdr lat))))))

(rember 'a '(a b a c))
(rember 'a '())
(rember 'a '(c d e))
(rember 'a '(b a c a d))

(define (firsts l)
  (cond
   ((null? l) '())
   (else (cons (car (car l))
               (firsts (cdr l))))))

(firsts '((a b)
          (c d)
          (e f)))
(firsts '())
(firsts '((a b)
          ((c) d)))

(define (insertR new old lat)
  (cond
   ((null? lat) '())
   ((eq? old (car lat))
    (cons old (cons new (cdr lat))))
   (else
    (cons (car lat)
          (insertR new old (cdr lat))))))

(insertR 'a 'b '(c d e b f))
(insertR 'a 'b '(c d e b f b))
(insertR 'a 'b '())
