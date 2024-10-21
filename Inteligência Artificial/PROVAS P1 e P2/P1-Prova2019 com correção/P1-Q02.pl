
apagar([E|Cauda],1,E,Cauda).
apagar([X|Cauda],N,E,[X|CaudaR]):- 	
	N1 is N-1, 
	apagar(Cauda,N1,E,CaudaR).
