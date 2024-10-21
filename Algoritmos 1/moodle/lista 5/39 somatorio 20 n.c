#include <stdio.h>
#include <math.h>

double fatorial(double j) {
    double i, fat = 1;
    for (i = 1; i <= j; i++)
    {
        fat *= i;
    }
    return fat;
}

int main()
{
    double j, s = 0, i, sinal, x;

    scanf("%lf", &x);

    for (j = 1.0, i = 1.0, sinal = 1; j <= 40.0; j *= 2, i += 2, sinal = -sinal)
    {
        s +=  sinal * pow(x, j) / fatorial(i);
        printf("%.2lf/%.2lf = %.2lf\n\n", sinal * pow(x, j) , fatorial(i), s);
    }
    
    return 0;
}