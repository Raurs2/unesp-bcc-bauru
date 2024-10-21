produto(1, 15.30, 23).
produto(2, 123.45, 13).
produto(3, 0.99, 100).
produto(4, 12.00, 33).
produto(5, 25.00, 55).
produto(6, 52.90, 99).

venda(ID, Valor):-
    produto(ID, Preco, _),
    Valor is Preco * 1.23.

estoque(ID, Total):-
    produto(ID, _, Quantidade),
    Total is Quantidade.

consulta(ID, Preco, Estoque):-
    venda(ID, Preco),
    estoque(ID, Estoque).
