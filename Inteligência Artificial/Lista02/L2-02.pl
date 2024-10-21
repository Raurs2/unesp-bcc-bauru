seculo(Ano,20):- Ano >= 1900, Ano <2000.
seculo(Ano,19):- Ano >= 1800, Ano <1900.

qual_seculo:-
	write('Diga o ano: '), read(Ano),
	seculo(Ano,S), 
	write('seculo = '),write(S).