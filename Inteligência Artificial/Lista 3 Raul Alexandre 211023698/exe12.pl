inserir_ultimo(E, [], [E]):-!.

inserir_ultimo(E, [H|T], [H|R]):-
    inserir_ultimo(E, T, R).
