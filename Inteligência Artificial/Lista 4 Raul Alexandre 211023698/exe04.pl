oceano(atlantico).
oceano(pacifico).
oceano(indico).
oceano(artico).

pais(brasil).
pais(japao).
pais(coreia).
pais(argentina).
pais(eua).
pais(canada).
pais(mexico).
pais(china).
pais(portugal).
pais(inglaterra).

continente(america_sul).
continente(america_norte).
continente(america_central).
continente(europa).
continente(asia).

fronteira(brasil, atlantico).
fronteira(brasil, argentina).
fronteira(japao, pacifico).
fronteira(china, coreia).
fronteira(coreia, pacifico).
fronteira(china, pacifico).
fronteira(portugal, atlantico).
fronteira(mexico, eua).
fronteira(mexico, atlantico).
fronteira(eua, canada).
fronteira(inglaterra, atlantico).

loc(brasil, america_sul).
loc(argentina, america_sul).
loc(canada, america_norte).
loc(eua, america_norte).
loc(mexico, america_norte).
loc(portugal, europa).
loc(inglaterra, europa).
loc(japao, asia).
loc(coreia, asia).
loc(china, asia).

%Quais paises fazem fronteira com oceano?
fronteiraComOceano(Pais):-
    pais(Pais),
    oceano(Oceano),
    fronteira(Pais, Oceano).

%Ache os pares de paises A e B tal que: A e B tem a mesma fronteira e fazem fronteiras com oceanos diferentes (ou seja, A faz fronteira com um oceano e B com outro;A e B nao fazem fronteira com o mesmo oceano).
paresPaisesOceanoDif(PaisA, PaisB):-
    pais(PaisA), pais(PaisB), PaisA\=PaisB,
    oceano(Oceano1), oceano(Oceano2), Oceano1\=Oceano2,
    fronteira(PaisA, PaisB),
    fronteira(PaisA, Oceano1),
    fronteira(PaisB, Oceano2).

%Ache os pares de paises localizados em diferentes continentes que fazem fronteiracom um mesmo oceano.
paresPaisesOceanoIgual(PaisA, PaisB):-
    pais(PaisA), pais(PaisB), PaisA\=PaisB,
    oceano(Oceano),
    fronteira(PaisA, PaisB),
    loc(PaisA, Continente1),
    loc(PaisB, Continente2),
    Continente2 \= Continente1,
    fronteira(PaisA, Oceano),
    fronteira(PaisB, Oceano).
