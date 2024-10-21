caixa(c1,10,5,2).
caixa(c2,6,2,5).
caixa(c3,6,3,3).
caixa(c4,5,5,3).

volume(Mod,V):-
	caixa(Mod,A,L,P),
	V is A*L*P.
medida(Mod,altura,Med):- caixa(Mod,Med,_,_).