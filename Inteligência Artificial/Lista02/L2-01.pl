distancia_sol(mercurio,36).
distancia_sol(venus,93).

distancia_planetas(X,Y,Dist):-
            distancia_sol(X,D1),
	    distancia_sol(Y,D2),
	    Dist is abs(D1 - D2).