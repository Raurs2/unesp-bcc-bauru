programa :-
   write('Digite seu peso (kg): '),
   read(P),

   write('Digite sua altura(m): '),
   read(A),

   write('IMC: '),
   Imc is P/(A*A),
   write(Imc), nl,
   testImc(Imc).


testImc(X) :-
   X =< 18.5, write('Abaixo do peso.');
   X =< 24.9, write('Peso ideal.');
   X =< 29.9, write('Acima do peso.');
   X =< 34.9, write('Obesidade grau I.');
   X =< 39.9, write('Obesidade grau II.');
   X >= 40, write('Obesidade grau III.').
