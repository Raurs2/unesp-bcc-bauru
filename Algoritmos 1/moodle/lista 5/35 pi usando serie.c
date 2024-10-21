#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, sinal;

    for (j = 1.0, sinal = 1.0; j <= 60.0; j += 2, sinal = -sinal)
    {
        s += sinal / pow(j, 3.0);
        printf("%.2lf/%.2lf^3 = %.2lf\n\n", sinal, j, s);
    }

    printf("pi = %lf\n", pow(32.0 * s, 1.0/3.0));

    return 0;
}