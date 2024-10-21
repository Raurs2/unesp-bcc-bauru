primeiro_prato(sl_palmito,20.0).
primeiro_prato(sl_tomate,10.0).
primeiro_prato(sl_folhas,15.5).
prato_principal(peixe,46.0).
prato_principal(frango,35.0).
prato_principal(picanha,80.0).
sobremesa(sl_frutas,10.5).
sobremesa(sorvete,12.5).
sobremesa(pudim,8.5).

cardapio(PP,Princ,Sobr,Max,Custo):- 
	primeiro_prato(PP,C1),
	prato_principal(Princ,C2),
	sobremesa(Sobr,C3),
	Custo is C1+C2+C3,
	Custo=<Max.