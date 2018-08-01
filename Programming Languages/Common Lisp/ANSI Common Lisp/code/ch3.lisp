(defun our-listp (x)
  (or (null x)
      (consp x)))

(defun our-atom (x)
  (not (consp x)))

(defun our-equal (x y)
  (or (eql x y)
      (and (consp x)
           (consp y)
           (our-equal (car x)
                      (car y))
           (our-equal (cdr x)
                      (cdr y)))))

(defun our-copy-list (lst)
  (if (atom lst)
      lst
      (cons (our-copy-list (car lst))
            (our-copy-list (cdr lst)))))

(defun our-copy-list-v2 (lst)
  (if (atom lst)
      lst
      (cons (car lst)
            (our-copy-list-v2 (cdr lst)))))

(let ((x '(a b c)))
  (format t "original x = ~a~%" x)
  (let ((y `(e ,x)))
    (format t "y = ~a~%" y)
    (let ((y1 (our-copy-list y))
          (y2 (our-copy-list-v2 y)))
      (format t "y1 = ~a~%" y1)
      (format t "y2 = ~a~%" y2)
      (setf (cadr x) 'z)
      (format t "changed x = ~a~%" x)
      (format t "y1 = ~a~%" y1)
      (format t "y2 = ~a~%" y2))))

(let ((x '(a b c))
      (y '(1 2 3)))
  (format t "x = ~a~%y = ~a~%" x y)
  (format t "~a~%" (append y x))
  (format t "x = ~a~%y = ~a~%" x y))

(defun n-elts (n elt)
  "create a sub compression"
  (if (> n 1)
      (list n elt)
      elt))

(defun compr (elt n lst)
  "find and create compression"
  (if (null lst)
      (list (n-elts n elt))
      (let ((next (car lst)))
        (if (equal elt next)
            (compr elt (+ n 1) (cdr lst))
            (cons (n-elts n elt)
                  (compr next 1 (cdr lst)))))))

(defun compress (x)
  "compress a list"
  (if (consp x)
      (compr (car x) 1 (cdr x))
      x))

(defun list-of (n elt)
  "make a list of n elts"
  (if (zerop n)
      nil
      (cons elt (list-of (- n 1) elt))))

(defun uncompress (lst)
  "uncompress a list"
  (if (null lst)
      nil
      (let ((cur (car lst)))
        (if (consp cur)
            (append (apply #'list-of cur) (uncompress (cdr lst)))
            (cons cur (uncompress (cdr lst)))))))

(defun our-nthcdr (n lst)
  (if (or (null lst) (zerop n))
      lst
      (our-nthcdr (- n 1) (cdr lst))))

(defun our-copy-tree (tr)
  (if (atom tr)
      tr
      (cons (our-copy-tree (car tr))
            (our-copy-tree (cdr tr)))))

(defun our-subst (new old tree)
  (if (atom tree)
      (if (equal old tree)
          new
          tree)
      (cons (our-subst new old (car tree))
            (our-subst new old (cdr tree)))))

(defun our-member-if (fn lst)
  (and (consp lst)
       (if (funcall fn (car lst))
           lst
           (our-member-if fn (cdr lst)))))

(defun palindrome? (lst)
  (let ((len (length lst)))
    (let ((mid (floor len 2)))
      (let ((half (subseq lst 0 mid)))
        (if (evenp len)
            (equal half
                   (reverse (subseq lst mid)))
            (equal half
                   (reverse (subseq lst (+ 1 mid)))))))))

(defun nthmost (n lst)
  (nth (- n 1)
       (sort (copy-list lst) #'>)))

(let ((x (car lst)))
  (setf lst (cdr lst))
  x)

(let ((x '(b)))
  (format t "x = ~a~%" x)
  (push 'a x)
  (let ((y x))
    (format t "y = ~a~%" y)
    (pop x)
    (format t "x = ~a, y = ~a~%" x y)))

(defun our-reverse (lst)
  (let ((acc nil))
    (dolist (x lst)
      (push x acc))
    acc))

(defun proper-list? (lst)
  (or (null lst)
      (and (consp lst)
           (proper-list? (cdr lst)))))

(let ((trans '((+ . "add")
               (- . "substract"))))
  (format t "~a~%" (assoc '+ trans))
  (format t "~a~%" (assoc '- trans))
  (format t "~a~%" (assoc '/ trans)))

(defun our-assoc (key alist)
  (and (consp alist)
       (let ((pair (car alist)))
         (if (equal key (car pair))
             pair
             (our-assoc key (cdr alist))))))

(defun new-paths (path node net)
  (mapcar #'(lambda (x) (cons x path))
          (cdr (assoc node net))))

(defun dfs (end queue net)
  (if (null queue)
      nil
      (let ((path (car queue)))
        (let ((node (car path)))
          (if (equal node end)
              (reverse path)
              (dfs end
                   (append (cdr queue)
                           (new-paths path node net))
                   net))))))

(defun shortest-path (start end net)
  (dfs end (list (list start)) net))

'(a . (b . ((c . (d . nil)) . nil)))
'(a . ((b . ((c . ((d . nil)))))))
'(((a . (b . nil)) . (c . nil)) . (d . nil))
'(a . ((b . c) . d))

(defun new-union (alst blst)
  (if (null blst)
      alst
      (let ((elem (car blst)))
        (if (member elem alst)
            (new-union alst
                       (cdr blst))
            (new-union (append alst (list elem))
                       (cdr blst))))))

(defun occurrences (lst)
  (let ((alist nil))
    (dolist (x lst)
      (let ((match (assoc x alist)))
        (if match
            (setf (cdr match)
                  (+ 1 (cdr match)))
            (setf alist
                  (cons (cons x 1)
                        alist)))))
    (sort alist #'> :key #'cdr)))

(defun pos+-rec-helper (lst i)
  (if (null lst)
      nil
      (cons (+ i (car lst))
            (pos+-rec-helper (cdr lst) (+ i 1)))))

(defun pos+-rec (lst)
  (pos+-rec-helper lst 0))

(defun pos+-iter (lst)
  (do ((i 0 (+ i 1))
       (tail lst (cdr tail))
       (res nil))
      ((null tail) (reverse res))
    (setf res (cons (+ i (car tail))
                    res))))

(defun inc-one ()
  (let ((x 0)
        (res))
    (lambda (item)
      (setf res (+ item x))
      (setf x (+ 1 x))
      res)))

(defun pos+-map (lst)
  (let ((fun (inc-one)))
    (mapcar fun lst)))

(defun cons-new (a b)
  (cons b a))

(defun list-new ())

(defun length-new (lst)
  (if (null lst)
      0
      (+ 1 (length-new (car lst)))))

(defun member-new (obj lst)
  (if (atom lst)
      nil
      (if (equal obj (cdr lst))
          lst
          (member-new obj (car lst)))))

(defun n-elts-new (n elt)
  (if (> n 1)
      (cons n elt)
      elt))

(defun compr-new (elt n lst)
  (if (null lst)
      (n-elts-new n elt)
      (if (equal elt (car lst))
          (compr-new elt
                     (+ 1 n)
                     (cdr lst))
          (cons (n-elts-new n elt)
                (compr-new (car lst)
                           1
                           (cdr lst))))))

(defun compress-new (lst)
  (if (consp lst)
      (compr-new (car lst)
                 1
                 (cdr lst))
      lst))

(defun showdots (lst)
  (if (null lst)
      (format t "~a" nil)
      (if (consp lst)
          (progn (format t "(")
                 (showdots (car lst))
                 (format t " . ")
                 (showdots (cdr lst))
                 (format t ")"))
          (format t "~a" lst))))

(defun dfs-longest (visited queue net res)
  (if (null queue)
      res
      (let ((path (car queue)))
        ())))
