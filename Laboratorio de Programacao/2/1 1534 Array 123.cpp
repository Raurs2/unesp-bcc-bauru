#include <stdio.h>

#define MAX 70
/*
    fiz um duplo for para construir a matriz e outro para mostra-la, pra construir coloquei 3 uma para atribuir todos as posições da diagonal secundaria com o valor 2
    outra para atribuir a diagonal principal com valor 1 e por fim se não esta contido nas diagonais entao atribui o valor 3.
*/
int main()
{
    int n, v[MAX][MAX], dP, dS;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0, dP = 1, dS = n; i < n; i++, dS--, dP++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j+1 == dS) v[i][j] = 2;
                else if (j+1 == dP) v[i][j] = 1;
                else v[i][j] = 3;
            }    
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d", v[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
