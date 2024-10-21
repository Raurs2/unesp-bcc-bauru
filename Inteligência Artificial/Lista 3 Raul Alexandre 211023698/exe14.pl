substitui(_, _, [], []):-!.

substitui(Alvo, Novo, [Alvo|Resto], [Novo|Resultado]) :-
    substitui(Alvo, Novo, Resto, Resultado).
substitui(Alvo, Novo, [H|Resto], [H|Resultado]) :-
    Alvo \= H,
    substitui(Alvo, Novo, Resto, Resultado).