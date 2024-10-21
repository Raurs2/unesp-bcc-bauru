retirar_ocor(_, [], []):-!.

retirar_ocor(E, [E|R], Lista_resultante) :-
    retirar_ocor(E, R, Lista_resultante).

retirar_ocor(E, [H|R], [H|Lista_resultante]) :-
    E \= H,
    retirar_ocor(E, R, Lista_resultante).