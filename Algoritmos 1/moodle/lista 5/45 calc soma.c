#include <stdio.h>
#include <math.h>

int main()
{
    double j, esqDi = 0, sinal = 1, diEsq = 0, posEsqDi = 0, posDiEsq = 0, negEsqDi = 0, negDiEsq = 0, i;

    for (j = 1.0, i = 10000.0; j <= 10000.0; j++, sinal = -sinal, i--)
    {
        esqDi +=  sinal / j;
        if (sinal == 1)
        {
            posEsqDi += sinal / j;
        } else if (sinal == -1)
        {
            negEsqDi += sinal / j;
        }

        diEsq +=  sinal / i;
        if (sinal == 1)
        {
            posDiEsq += sinal / i;
        } else if (sinal == -1)
        {
            negDiEsq += sinal / i;
        }
    }
    
    printf("esqDi = %.2lf\n+ = %.2lf\n- = %.2lf\nDiEsq = %.2lf\n+ = %.2lf\n- = %.2lf\n", esqDi, posEsqDi, negEsqDi, diEsq, posDiEsq, negDiEsq);

    return 0;
}