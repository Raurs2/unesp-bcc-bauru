n_esimo(1, Elemento, [Elemento|_ ]):-!.
n_esimo(N, Elemento, [ _|Cauda ]):- N1 is N - 1, 
    n_esimo(N1, Elemento, Cauda).

no_elementos([],0):-!.
no_elementos([_|Y],N):- no_elementos(Y,N1), N is N1+1.

tire_elemento(_, [], []):-!.
tire_elemento(Elem, [Elem|Cauda], Cauda):-!.
tire_elemento(Elem, [Elem1|Cauda], [Elem1|Cauda1]):-
 tire_elemento(Elem, Cauda, Cauda1).

duplicar_um(_,[],[]).
duplicar_um(X,[X|C],[X,X|C]).
duplicar_um(X,[Y|Cauda],[Y|Cauda1]):-
duplicar_um(X,Cauda,Cauda1).