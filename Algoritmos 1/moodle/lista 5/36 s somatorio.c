#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, sinal, i;

    for (j = 15.0, sinal = 1.0, i = 1.0; j >= 1.0; j--, sinal = -sinal, i *= 2)
    {
        s += (sinal * i) / (j*j);
        printf("%.2lf/%.2lf = %lf\n\n", sinal * i, j*j, s);
    }

    return 0;
}