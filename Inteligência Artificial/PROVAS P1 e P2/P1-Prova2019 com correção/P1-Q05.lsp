(defun soma (L1 L2 LR)
	(if (and (= null L1) (= null L2)) nil
	    (if (and (= null L1) (not (= null L2)))
		(append L2 LR))))

		;(if (and (not (= null L1))(= null L2))
		;    (append L1 LR)
		 ;   ((append (+ (car L1) (car L2)) LR)
		;	     (soma (cdr L1) (cdr L2) LR))))))
(defun soma2 (lista1 lista2)
(if (null lista1) lista2
(if (null lista2) lista1
(cons (+ (first lista1)(first lista2))
(soma2 (rest lista1) (rest lista2))))))	