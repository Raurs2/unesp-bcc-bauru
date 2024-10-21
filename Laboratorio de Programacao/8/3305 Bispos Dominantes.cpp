#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// testei se a soma x + y dos bispos fossem iguais entao eles estariam na mesma diagonal e se 
// a subtracao x - y deles fossem iguais eles estariam na mesma diagonal secundaria
// entao se o bispo n tem soma ou sub igual nenhum ele é dominante

int main()
{
    int n, x[100001], y[100001], mais[100001], menos[100001], dominante, secun, prima, mesmo, dominantes = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        mais[i] = x[i] + y[i];
        menos[i] = x[i] - y[i];
    }
    for (int i = 0; i < n; i++)
    {
        dominante = 1;
        for (int j = 0; j < n; j++)
        {
            
            if (i != j)
            {
                if (mais[i] == mais[j] || menos[i] == menos[j])
                {
                    dominante = 0;
                    break;
                }
            }
        }
        if (dominante) dominantes++;
    }
    
    printf("%d\n", dominantes);
    return 0;
}
