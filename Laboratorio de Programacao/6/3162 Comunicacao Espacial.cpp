#include <stdio.h>
#include <math.h>
/*
    peguei o n de naves e depois coloquei as coord de cada uma, dps testei a distancia de uma nave para a outra e se for a menor 
    distancia eu printo a intensidade do sinal, isso para cada nave.
*/
int main()
{
    int n;
    scanf("%d", &n);

    int x[n], y[n], z[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &x[i], &y[i], &z[i]);   

    char sinal;
    double forca, menor;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            forca = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2));
            if (j == 0) menor = 999;
            if (forca != 0 && forca < menor) menor = forca;
        }

        if (menor <= 20) sinal = 'A';
        else if (menor <= 50) sinal = 'M';
        else sinal = 'B';

        printf("%c\n", sinal);
    }

    return 0;
}
