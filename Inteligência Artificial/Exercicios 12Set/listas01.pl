pertence(Elemento,[Elemento|_]):-!.
pertence(Elemento,[_|Cauda]):-pertence(Elemento,Cauda).

soma([ ],0).
soma([Cabeca|Cauda], S):- soma(Cauda, S1), S is S1 + Cabeca.

consecutivos(E1, E2, [ E1, E2 | _]).
consecutivos(E1, E2, [ _ | Cauda]):- consecutivos( E1, E2, Cauda).