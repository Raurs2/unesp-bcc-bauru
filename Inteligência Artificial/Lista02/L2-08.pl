nota_media(Escola,Ano,Media):-
	escola(Escola,Ano,Lista),
	soma(Lista,S),no_elementos(Lista,N),
	Media is S/N.

nota_quesito(Escola,Ano,Quesito,Nota):- 
	escola(Escola,Ano,Lista),
	pos_nota(Quesito,N),
	n_esimo(N,Lista,Nota).

n_esimo(1,[X|_],X).
n_esimo(N,[_|Y],E):-
	N1 is N-1,
	n_esimo(N1,Y,E).

soma([],0).
soma([X|Y],S):- soma(Y,S1),S is S1 + X.

no_elementos([],0).
no_elementos([_|Y],S):- no_elementos(Y,S1),S is S1 + 1.


escola(beija_flor,1990,[5,10,10,10,10,10,10,10,10,10]).
escola(beija_flor,1991,[8,10,10,10,10,10,10,10,10,10]).
escola(beija_flor,1992,[7,10,10,10,10,10,10,10,10,10]).
escola(portela,1990,[10,9,10,9,8,9,10,9,10,9]).

pos_nota(alegoria,1).
pos_nota(bateria,2).
pos_nota(madrinha,3).
pos_nota(porta_bandeira,4).
pos_nota(enredo,5).
pos_nota(harmonia,6).
pos_nota(fantasias,7).
pos_nota(comissao_frente,8).
pos_nota(quesito_9,9).
pos_nota(quesito_10,10).
