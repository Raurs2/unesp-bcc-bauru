#include <stdio.h>
void fatorial(double x, double * fat){
    *fat = 1;
    for (x; x > 0; x--)
        *fat *= x;
}
int main()
{
    double x, fat;
    do
    {
        scanf("%lf", &x);
        if ((int)(x) == 0) break;
        fatorial(x, &fat);
        printf("fat de %.1lf = %.1lf\n\n", x, fat);
    } while (1);
    return 0;
}
