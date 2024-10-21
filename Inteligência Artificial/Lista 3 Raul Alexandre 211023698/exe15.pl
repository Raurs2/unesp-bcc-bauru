duplicar_todos([], []):-!.

duplicar_todos([X | R], [X, X | Resultado]) :-
    duplicar_todos(R, Resultado).