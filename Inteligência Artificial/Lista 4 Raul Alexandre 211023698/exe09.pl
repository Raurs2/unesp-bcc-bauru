pos_nota(p1, 1).
pos_nota(p2, 2).
pos_nota(p3, 3).
pos_nota(t1, 4).
pos_nota(t2, 5).
pos_nota(t3, 6).
pos_nota(e1, 7).
pos_nota(e2, 8).
pos_nota(e3, 9).
pos_nota(s, 10).

aluno(manoel, 2000, [10, 9, 8, 10, 10, 10, 9, 9, 10, 8]).
aluno(maria, 2000, [10, 10, 10, 10, 10, 10, 9, 9, 10, 8]).
aluno(rohan, 2002, [10, 10, 9, 10, 10, 10, 10, 9, 10, 9]).
aluno(kishibe, 2002, [8, 10, 10, 9, 10, 5, 5, 5, 6, 8]).
aluno(saikou, 2021, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]).
aluno(saigo, 2021, [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]).
aluno(juri, 2023, [10, 9, 9, 10, 8, 10, 10, 10, 9, 9]).
aluno(aki, 2023, [8, 7, 9, 6, 8, 9, 10, 10, 9, 9]).

nota_media_P1(Ano, Media) :-
    findall(Nota, (aluno(_, Ano, Lista_notas),
                  buscarNota(1, Lista_notas, Nota)), Notas),
    somaNotas(Notas, Soma),
    quantidadeNotas(Notas, Quantidade),
    Media is Soma / Quantidade.

nota_avaliacao(Nome, Ano, Avaliacao, Nota):-
    aluno(Nome, Ano, Lista_notas),
    pos_nota(Avaliacao, Pos),
    buscarNota(Pos, Lista_notas, Nota).


buscarNota(1, [Cabeca|_], Cabeca) :-!.

buscarNota(N, [_|Cauda], E) :-
    X is N-1,
    buscarNota(X, Cauda, E).

somaNotas([], 0) :-!.
somaNotas([X|Y], S) :-
    somaNotas(Y, S1),
    S is S1 + X.

quantidadeNotas([], 0) :-!.

quantidadeNotas([_|Y], N) :-
    quantidadeNotas(Y, N1),
    N is N1 + 1.
