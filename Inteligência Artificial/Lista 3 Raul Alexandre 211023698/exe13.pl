inserir_N(E, 1, L, [E|L]):-!.

inserir_N(E, N, [H|T], [H|Lista_resultante]):-
    X is N-1,
    inserir_N(E, X, T, Lista_resultante).
