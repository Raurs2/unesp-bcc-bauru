#include<stdio.h>
#include <stdlib.h>

// fiz uma funcao recursiva para calcular o valor em binario, e uma matriz para salvar os acessos de cada dia de cada semana
// somei o total de acessos de cada semana para saber qual semana deve maior acesso

int main()
{
    int acessos[4][7], tot, mais_acesso = 0;
    char a[1000], buffer[50];
    for (int i = 0; i < 4; i++)
    {
        tot = 0;
        
        for (int j = 0; j < 7; j++)
        {
            scanf("%d", &acessos[i][j]);
            tot += acessos[i][j];
        }

        if (tot > mais_acesso) mais_acesso = tot;
    }

    itoa(mais_acesso, a, 2);
    sprintf(buffer, "%d = %s\n", mais_acesso, a)
    printf("%d = %s\n", mais_acesso, a);
    
    return 0;
}
