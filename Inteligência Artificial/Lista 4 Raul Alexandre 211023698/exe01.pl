distancia_sol(mercurio, 36).
distancia_sol(venus, 67).
distancia_sol(terra, 93).
distancia_sol(marte, 141).
distancia_sol(jupiter, 484).
distancia_sol(saturno, 886).
distancia_sol(uranio, 1790).
distancia_sol(netuno, 2800).
distancia_sol(plutonio, 4600).


distancia_planetas(Planeta1, Planeta2, Distancia) :-
    distancia_sol(Planeta1, Distancia1),
    distancia_sol(Planeta2, Distancia2),
    Distancia is abs(Distancia1 - Distancia2).
