pos_nota(alegorias, 1).
pos_nota(bateria, 2).
pos_nota(naoSei, 3).
pos_nota(naoSei2, 4).
pos_nota(naoSei3, 5).
pos_nota(tabom, 6).
pos_nota(taruim, 7).
pos_nota(musica, 8).
pos_nota(danca, 9).
pos_nota(fantasia, 10).

escola(sambaBom,1999,[10, 10, 10, 10, 10, 10, 10, 10, 10, 10]).
escola(sambaRuim,1999,[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]).
escola(sambaMedio,1999,[5, 5, 5, 5, 5, 5, 5, 5, 5, 5]).
escola(sambinha,2003,[10, 9, 10, 9, 8, 9, 10, 9, 10, 9]).
escola(sambao, 2012, [10, 10, 10, 9, 9, 10, 9, 8, 10, 10]).
escola(sambado, 2023, [3, 4, 5, 6, 7, 8, 9, 10, 9, 8]).
escola(samsamba, 2017, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]).

nota_media(Escola, Ano, Media) :-
    escola(Escola, Ano, Lista_notas),
    somaNotas(Lista_notas, Soma),
    quantidadeNotas(Lista_notas, Quantidade),
    Media is Soma / Quantidade.

nota_quesito(Escola, Ano, Quesito, Nota_quesito) :-
    escola(Escola, Ano, Lista_notas),
    buscarNota(Quesito, Lista_notas, Nota_quesito).

media_quesito(Escola, Quesito, Nota_media) :-
   findall(Nota, (escola(Escola, _, Lista_notas),
                  pos_nota(Quesito, Pos),
                  buscarNota(Pos, Lista_notas, Nota)), Notas),
   somaNotas(Notas, Soma),
   quantidadeNotas(Notas, Quantidade),
   Nota_media is Soma / Quantidade.


buscarNota(1, [Cabeca|_], Cabeca) :-!.

buscarNota(N, [_|Cauda], E) :-
    X is N-1,
    buscarNota(X, Cauda, E).



somaNotas([], 0) :-!.

somaNotas([X|Y], S):-
    somaNotas(Y, S1),
    S is S1 + X.

quantidadeNotas([], 0) :-!.

quantidadeNotas([_|Y], N):-
    quantidadeNotas(Y, N1),
    N is N1 + 1.
