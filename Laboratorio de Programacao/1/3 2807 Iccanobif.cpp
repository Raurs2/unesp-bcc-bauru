#include <stdio.h>
#include <stdlib.h>

/*
    Eu pensei em fazer com um vetor, primeiro ja coloquei as posicoes 0 e 1 que sempre serao 1 e depois fiz um while para armazenar o valor das outras posicoes da sequencia
    ele faz uma soma entre dois valores dando o proximo valor e assim vai ate chegar no tamanho da sequencia que a pessoa quer, depois usei um for que comeca no final da sequencia
    e vai para o inicio para printar no jeito que o exercicio pede
*/


int main()
{
    int n, num[41], i = 2, n1 = 1, n2 = 1, nf, x;

    scanf("%d", &n);
    x = n;
    num[0] = 1;
    num[1] = 1;

    if (n > 2)
    {    
        while (n != 0)
        {
            nf = n1 + n2;
            num[i] = nf;
            i++;
            n1 = n2;
            n2 = nf;
            n--;
        }
    }
    
    for ( i = x-1; i >= 0; i--)
    {
        printf("%d", num[i]);
        if (i != 0) printf(" ");
    }

    printf("\n");
    
    return 0;
}
