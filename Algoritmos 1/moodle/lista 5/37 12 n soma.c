#include <stdio.h>
#include <math.h>

double fatorial(double j) {
    double i, fat = 1;
    if (j == 0) return fat;
    for (i = 1; i <= j; i++)
    {
        fat *= i;
    }
    return fat;
}

int main()
{
    double j, s = 0, i;
    s = 100;

    for (j = 1.0, i = 99.0; j <= 12.0; j++, i--)
    {
        s += i / fatorial(j);
        printf("%.2lf/%.2lf = %.2lf\n\n", i, fatorial(j), s);
    }

    return 0;
}