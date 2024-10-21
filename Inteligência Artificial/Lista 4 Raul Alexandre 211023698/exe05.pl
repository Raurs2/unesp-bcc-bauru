primeiro_prato(salada_palmito, 15.0).
primeiro_prato(gafanhotos, 13.0).
primeiro_prato(alface, 2.5).
primeiro_prato(camarao, 22.5).

prato_principal(peixe, 40.6).
prato_principal(bife_acebolado, 20.0).
prato_principal(lasanha, 35.0).
prato_principal(macarrao, 22.5).

sobremesa(salada_frutas, 12.0).
sobremesa(arroz_doce, 1.0).
sobremesa(sorvete, 6.0).
sobremesa(chocolate, 3.0).

cardapio(PrimPrato, PratoPrinc, Sobr, Min, Max, Custo) :-
    primeiro_prato(PrimPrato, Custo1),
    prato_principal(PratoPrinc, Custo2),
    sobremesa(Sobr, Custo3),
    CustoTotal is Custo1 + Custo2 + Custo3,
    CustoTotal >= Min, CustoTotal =< Max, Custo is CustoTotal.
