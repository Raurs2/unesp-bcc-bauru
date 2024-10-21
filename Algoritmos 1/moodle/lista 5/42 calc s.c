#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, x, sinal = 1;

    scanf("%lf", &x);

    for (j = 1.0; j <= 20; j++, sinal = -sinal)
    {
        s +=  sinal * x / j;
        printf("%.2lf/%.2lf = %.2lf\n\n", sinal * x, j, s);
    }
    
    return 0;
}