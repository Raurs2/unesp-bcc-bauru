oceano(atlantico).
pais(brasil).
continente(america_sul).
fronteira(brasil,atlantico).
fronteira(brasil,argentina).
loc(brasil,america_sul).

%Quais países fazem fronteira com oceanos?
pergA(A,B):-
	pais(A), pais(B), A\=B,
	oceano(O1),oceano(O2),
	fronteira(A,O1),
	fronteira(B,O2).