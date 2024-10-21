#include <stdio.h>
#include <math.h>

int main()
{
    float i, j, s = 0, sinal;

    for (i = 1, j = 1, sinal = 1; i <= 10; i++, j++, sinal = -sinal)
    {
        s += sinal * i*i / j;
        printf("%.2f/%.2f = %.2f\n", sinal * i*i, j, s);
    }

    return 0;
}