caixa(caixinha, 1, 1, 1).
caixa(caixote, 3, 6, 4).
caixa(caixao, 10, 12, 13).
caixa(bau, 5, 3, 10).
caixa(bigcaixao, 20, 24, 26).

volume(Modelo, Volume):-
    caixa(Modelo, Altura, Largura, Profundidade),
    Volume is Altura * Largura * Profundidade.

medida(Modelo, Tipo, Medida):-
    Tipo == 'Altura', caixa(Modelo, Medida, _, _);
    Tipo == 'Largura', caixa(Modelo, _, Medida, _);
    Tipo == 'Profundidade', caixa(Modelo, _, _, Medida).

consulta(Modelo, Volume):-
    caixa(Modelo, Altura, Largura, _),
    Altura == Largura,
    volume(Modelo, Volume).
