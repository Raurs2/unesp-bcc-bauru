% empregado (NumEmp, NomeEmp, Salario, NumDepto)
empregado(32,jSilva,380,21).
empregado(74,mReis,400,25).
empregado(89,cMelo,520,28).
empregado(92,rSilva,480,25).
empregado(112,rPinto,390,21).
empregado(121,vSimao,905,28).
empregado(130,jNeves,640,28).

% departamento (NumDepto, NomeDepto, Ramal)
departamento(21, pessoal, 142).
departamento(25, financeiro, 143).
departamento(28, tecnico, 144).


% a)Qual o ramal do Empregado X?
consulta01(Empregado,Departamento,Ramal):-
	empregado(_,Empregado,_,NumDepto),
	departamento(NumDepto,Departamento,Ramal).

% b)Quais Empregados trabalham no Departamento X ?
consulta02(Depto,Empregados):-
	findall(Empregado,(empregado(_,Empregado,_,NumDepto),
			   departamento(NumDepto,Depto,_)), Empregados).

consulta(Nome,Empregados):-
	departamento(Num,Nome,_), empdepto(Num,Empregados).

empdepto(Num,[Emp|Cauda]):-
	empregado(_,Emp,_,Num), empdepto(Num,Cauda).

% c)Valor total dos salários.
consulta03(ValorTotal):-
	findall(Salario,empregado(_,_,Salario,_),Salarios),
	soma(Salarios,ValorTotal).

soma([],0).
soma([Sal|Salarios],ValorTotal):-
	ValorTotal is Valor + Sal,	
	soma(Salarios,Valor).
%	ValorTotal is Valor + Sal.
