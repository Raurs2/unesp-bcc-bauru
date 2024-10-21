#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, x, sinal = 1, i = 25;

    scanf("%lf", &x);

    for (j = 1.0; j <= 25; j++, sinal = -sinal, i--)
    {
        s +=  sinal * pow(x, i) / j;
        printf("%.2lf/%.2lf = %.2lf\n\n", sinal * pow(x, i), j, s);
    }
    
    return 0;
}