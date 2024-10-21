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
    double j, s = 0, i, sinal;

    for (j = 1.0, i = 1.0, sinal = 1; j <= 20.0; j++, i = i * 2 + 1, sinal = -sinal)
    {
        s +=  sinal * fatorial(j) / i;
        printf("%.2lf/%.2lf = %.2lf\n\n", sinal * fatorial(j) , i, s);
    }
    
    return 0;
}