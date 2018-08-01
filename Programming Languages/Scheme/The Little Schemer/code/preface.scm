(define atom?
  (lambda (x)
    (and (not (pair? x))
         (not (null? x)))))

(atom? '())
(atom? 'atom)
(atom? '1492)
(list? '(atom))
(null? '())
(null? 'a)

(eq? 'Harry 'Harry)
(define a1 'Harry)
(define a2 'Harry)
(eq? a1 a2)

(define (lat? lst)
  (if (null? lst)
      #t
      (if (atom? (car lst))
          (lat? (cdr lst))
          #f)))

(lat? '(a b c))
(lat? '(a))
(lat? '())
(lat? '(a (b c) d))
(lat? '((a) b c d))

(define (member? a lst)
  (cond
   ((null? lst) #f)
   (else (or (eq? a (car lst))
             (member? a (cdr lst))))))

(member? 'a '(a b c))
(member? 'b '(a))
(member 'c '())
