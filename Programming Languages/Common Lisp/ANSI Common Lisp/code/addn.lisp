(define addn (n)
  #'(lambda (x)
      (+ n x)))

(defun our-third (lst)
  (car (cdr (cdr lst))))

(defun our-member (obj lst)
  (if (null lst)
      nil
      (if (eql obj (car lst))
          lst
          (our-member obj (cdr lst)))))

(defun askem (string)
  (format t "~a" string)
  (read))

(let ((x 1)
      (y 2))
  (+ x y))

(defun ask-number ()
  (format t "Please enter a number. ")
  (let ((x (read)))
    (if (numberp x)
        x
        (ask-number))))

(defparameter *glob* 99)

(defconstant limit (+ *glob* 1))

(setf x '(a b c d))
(setf (car x) 'e)

(set x 1
     y 2
     z 3)

(defun show-squares (start end)
  (do ((i start (+ 1 i)))
      ((> i end) 'done)
    (format t "~a ~a~%" i (* i i))))

(defun show-squares-rec (start end)
  (if (> start end)
      'done
      (progn
        (format t "~a ~a~%" start (* start start))
        (show-squares-rec (+ 1 start) end))))

(defun our-length (lst)
  (let ((len 0))
    (dolist (x lst)
      (setf len (+ 1 len)))
    len))

(defun our-length-rec (lst)
  (if (null lst)
      0
      (+ 1 (our-length-rec (cdr lst)))))

(lambda (x y) (+ x y))

((lambda (x y) (+ x y))
 2 3)

#'(lambda (x y) (+ x y))
(function (lambda (x y) (+ x y)))

;; 2
(cons 'a (cons 'b (cons 'c nil)))
(cons 'a (cons 'b '(c)))
(cons 'a '(b c))

;; 3
(defun our-fourth (lst)
  (car (cdr (cdr (cdr lst)))))

;; 4
(defun greater-two (x y)
  (if (> x y)
      x
      y))

;; 5
;; (a)
(defun enigma (x)
  (and (not (null x))
       (or (null (car x))
           (enigma (cdr x)))))

;; (b)
(defun mystery (x y)
  (if (null y)
      nil
      (if (eql (car y) x)
          0
          (let ((z (mystery x (cdr y))))
            (and z (+ z 1))))))

;; 6
;; (a)
(car (car (cdr '(a (b c) d))))

;; (b)
(or 13 (/ 1 0))

;; (c)
(apply #'list 1 nil)

;; 7
(defun contain-list (lst)
  (if (null lst)
      nil
      (if (listp (car lst))
          t
          (contain-list (cdr lst)))))

;; 8
;; (a)
(defun print-dots (n)
  (do ((i 0 (+ i 1)))
      ((equal i n) (format t "~%"))
    (format t ".")))

(defun print-dots-rec (n)
  (if (zerop n)
      (format t "~%")
      (progn
        (format t ".")
        (print-dots-rec (- n 1)))))

;; (b)
(defun count-a (lst)
  (let ((cnt 0))
    (dolist (x lst)
      (if (equal x 'a)
          (setf cnt (+ 1 cnt))))
    cnt))

(defun count-a-rec (lst)
  (if (null lst)
      0
      (if (equal 'a (car lst))
          (+ 1 (count-a-rec (cdr lst)))
          (count-a-rec (cdr lst)))))

;; 9
;; (a)
(defun summit (lst)
  (setf lst (remove nil lst))
  (apply #'+ lst))

;; (b)
(defun summit-rec (lst)
  (if (null lst)
      0
      (let ((x (car lst)))
        (if (null x)
            (summit-rec (cdr lst))
            (+ x (summit-rec (cdr lst)))))))

