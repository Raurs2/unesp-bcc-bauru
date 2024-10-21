aniversario(jose,5,maio,1985).
aniversario(simone,25,novembro,2222).
aniversario(joao,22,janeiro,2000).

signo(P, aquario) :- aniversario(P, Dia, janeiro, _), Dia >= 20.
signo(P, aquario) :- aniversario(P, Dia, fevereiro, _), Dia =< 18.







filho(X,Y):-homem(X), pai(Y,X).
filho(X,Y):-homem(X), mae(Y,X).
filha(X,Y):-mulher(X), (pai(Y,X); mae(Y,X)).

irmao(X,Y):- pai(Z,X), pai(Z,Y), homem(X), X\=Y.
irma(X,Y):- pai(Z,X), pai(Z,Y), mulher(X), X\=Y.

pai(ranulpho,zeferina).
pai(ranulpho,alcina).
pai(ranulpho,alvina).
pai(augustov,joaop).
pai(augustov,maria).
pai(joaop,joao).
pai(joaop,moises).
pai(joaop,augusto).
pai(joaop,simone).
pai(joaop,helves).
pai(joaop,valeria).
pai(joaop,elaine).
pai(miguel,barbara).

mae(rosaria,zeferina).
mae(rosaria,alcina).
mae(rosaria,alvina).
mae(zeferina,joao).
mae(zeferina,moises).
mae(zeferina,augusto).
mae(zeferina,simone).
mae(zeferina,helves).
mae(zeferina,valeria).
mae(zeferina,elaine).
mae(lidia,joaop).
mae(lidia,maria).
mae(simone,barbara).

homem(ranulpho).
homem(augustov).
homem(joaop).
homem(joao).
homem(moises).
homem(augusto).
homem(helves).

mulher(rosaria).
mulher(lidia).
mulher(zeferina).
mulher(alcina).
mulher(alvina).
mulher(maria).
mulher(simone).
mulher(valeria).
mulher(elaine).
mulher(sadora).
mulher(barbara).
