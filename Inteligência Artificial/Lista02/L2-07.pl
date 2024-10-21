produto(12,23.0,10).

venda(ID,Valor):-
	produto(ID,V1,_),
	Valor is V1*1.23.