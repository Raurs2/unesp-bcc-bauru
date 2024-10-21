#include<stdio.h>

// fiz uma funcao  para calcular o valor em binario, utilizando o metodo de pegar os restos da divisao e inverter a ordem, armazenei numa array, e uma matriz para salvar os acessos de cada dia de cada semana
// somei o total de acessos de cada semana para saber qual semana deve maior acesso

void intToBin(int n)
{
    int nBin[1000];
 
    int i = 0;
    while (n > 0)
    {
        nBin[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    for (int j = i - 1; j >= 0; j--)
        printf("%d", nBin[j]);
}

int main()
{
    int acessos[4][7], tot, mais_acesso = 0;

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

    printf("%d = ", mais_acesso);
    intToBin(mais_acesso);
    printf("\n");
    
    return 0;
}
