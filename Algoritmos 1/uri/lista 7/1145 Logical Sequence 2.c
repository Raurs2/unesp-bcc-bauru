#include <stdio.h>
#include <math.h>

/*
    esse programa a gente ja fez em algoritmo 1, é um exercicio para utilizar for duplo, primeiro o for exterior que vai variar de 1 ate o y do usuario e serao a quantidade de linhas
    e o for interno para printa os numeros nas colunas que tb vao crescendo conforme vao descendo as linhas.
*/

int main() {
    int x, y, i, j, m;
    scanf("%d %d", &x, &y);
    m = x;
    for (i = 1, j = 1; i <= y; i++, x += m)
    {
        for (j; j <= x; j++)
        {
            printf("%d", j);
            if (j < x) printf(" ");
        }
        printf("\n");
        if (j >= y) break;
    }
    
    return 0;    
}