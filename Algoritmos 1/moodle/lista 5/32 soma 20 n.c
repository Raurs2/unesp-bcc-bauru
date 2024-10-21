#include <stdio.h>
#include <math.h>

int main()
{
    float i, j, s = 0, sinal;

    for (i = 1000, j = 1, sinal = 1; j <= 20; i -= 3, j++, sinal = -sinal)
    {
        s += sinal * i / j;
        printf("%.2f/%.2f = %.2f\n", sinal * i, j, s);
    }

    return 0;
}