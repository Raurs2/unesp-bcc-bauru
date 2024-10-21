#include <stdio.h>
#include <math.h>

/*
    esse programa a gente ja fez em algoritmo 1, é simplesmente usar if com os operadores de comparacao == > e < para descobrir se eh igual descrescente ou crescente
*/

int main() {
    int x, y;
    do
    {
        scanf("%d %d", &x, &y);

        if (x == y) break;
        if (x > y) printf("Decrescente\n");
        if (x < y) printf("Crescente\n");

    } while (1);
    
    return 0;    
}