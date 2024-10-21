#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
    fiz um loop com os n testes, depois dentro dois for um para a pontuacao de joao e outro para a maria e para finalizar uma condicao para descobrir
    qual dos dois tem maior pontuacao.
*/
int main()
{
    int n, x, d, jo = 0, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++, jo = 0, m = 0)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d %d", &x, &d);
            jo += x * d;
        }
        for (int j = 0; j < 3; j++)
        {
            scanf("%d %d", &x, &d);
            m += x * d;
        }
        if (jo > m)
        {
            printf("JOAO\n");
        } else if (m > jo)
        {
            printf("MARIA\n");
        }
    }
    
    return 0;
}
