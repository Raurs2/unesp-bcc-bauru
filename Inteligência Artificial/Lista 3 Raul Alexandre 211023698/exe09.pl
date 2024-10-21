concatenar([], L, L):-!.

concatenar([H|T1], L2, [H|Lista_resultante]) :-
    concatenar(T1, L2, Lista_resultante).