#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, sinal = 1;

    for (j = 500.0; j >= 0; j -= 50, sinal = -sinal)
    {
        if (sinal == -1)
        {
            s +=  sinal * 5 / j;
            printf("%.2lf/%.2lf = %.2lf\n\n", sinal * 5, j, s);
        } else if (sinal == 1)
        {
            s +=  sinal * 2 / j;
            printf("%.2lf/%.2lf = %.2lf\n\n", sinal * 2, j, s);
        }
    }
    
    return 0;
}