#2a((0 0 0)
    (1 1 1))

#3a(((0 1 2))
    ((3 4 5)))

#|
implement binary search
|#

(defun finder (obj vec start end)
  (format t "~a~%"
          (subseq vec start (+ 1 end)))
  (if (>= end start)
      (let ((len (- end start)))
        (if (zerop len)
            (if (equal obj (svref vec start))
                obj
                nil)
            (let ((mid (+ start (round (/ len 2)))))
              (let ((obj-mid (svref vec mid)))
                (if (equal obj obj-mid)
                    obj
                    (if (> obj obj-mid)
                        (finder obj vec (+ 1 mid) end)
                        (finder obj vec start (- mid 1))))))))))

(defun bin-search (obj vec)
  (let ((len (length vec)))
    (and (not (zerop len))
         (finder obj vec 0 (- len 1)))))

;; book version
(defun finder-book (obj vec start end)
  (format t "~a~%"
          (subseq vec start (+ 1 end)))
  (let ((range (- end start)))
    (if (zerop range)
        (if (eql obj (aref vec start))
            obj
            nil)
        (let ((mid (+ start (round (/ range 2)))))
          (let ((obj2 (aref vec mid)))
            (if (< obj obj2)
                (finder-book obj vec start (- mid 1))
                (if (> obj obj2)
                    (finder-book obj vec (+ mid 1) end)
                    obj)))))))

(defun bin-search-book (obj vec)
  (let ((len (length vec)))
    (and (not (zerop len))
         (finder-book obj vec 0 (- len 1)))))

(defun mirror? (lst)
  (let ((len (length lst)))
    (do ((forward 0 (+ forward 1))
         (backward (- len 1) (- backward 1)))
        ((or (> forward backward)
             (not (equal (elt lst forward)
                         (elt lst backward))))
         (> forward backward)))))

(defun second-word (str)
  (let ((p1 (+ (position #\  str) 1)))
    (subseq str p1 (position #\  str :start p1))))

(defun tokens (str test start)
  (let ((p1 (position-if test str :start start)))
    (if p1
        (let ((p2 (position-if #'(lambda (c)
                                   (not (funcall test c)))
                               str
                               :start (+ 1 p1))))
          (cons (subseq str p1 p2)
                (if p2
                    (tokens str test p2)
                    nil))))))

(defun constituent (c)
  (and (graphic-char-p c)
       (not (char= c #\ ))))

(defconstant month-names
  #("Jan" "Feb" "Mar" "Apr" "May" "Jun"
    "Jul" "Aug" "Sep" "Oct" "Nov" "Dec"))

(defun parse-month (str)
  (let ((p (position str
                     month-names
                     :test #'string-equal)))
    (if p
        (+ p 1)
        nil)))

(defun parse-date (str)
  (let ((toks (tokens str #'constituent 0)))
    (list (parse-integer (first toks))
          (parse-month (second toks))
          (parse-integer (third toks)))))

(defun our-parse-integer (str)
  (if (every #'digit-char-p str)
      (let ((acc 0))
        (dotimes (i (length str))
          (setf acc (+ (* 10 acc)
                       (digit-char-p (char str i)))))
        acc)))

