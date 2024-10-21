#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
    pensei em calcular o valor certo e pegar o modulo da diferenca 
    entre o resultado certo errado colocando essa diferenca num for pra escrever os r
*/

int main () {
    int a, b, r, rReal, n, dist;
    char op, eq;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d %c %d", &a, &op, &b, &eq, &r);

        if (op == '+')
        {
            rReal = a + b;
        } else if (op == '-')
        {
            rReal = a - b;
        } else if (op == '/')
        {
            rReal = a / b;
        } else
        {
            rReal = a * b;
        }
        
        dist = abs(r - rReal);

        printf("E");
        for (int j = 1; j <= dist; j++)
        {
            printf("r");
        }
        printf("ou!\n");
    }
    
}