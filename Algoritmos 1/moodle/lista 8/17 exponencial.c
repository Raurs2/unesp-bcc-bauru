#include<stdio.h>
#include<math.h>

double fatorial(double x){
    double fat = 1;
    if (x == 0) return 1;
    for (x; x > 0; x--)
        fat *= x;
    return fat;
}

double potencia(double x, double y) {
    int i;
    double r = 1;
    if (y == 0) return 1;
    for (i = 1; i <= y; i++)
        r *= x;
    return r;
}

double exponencial(double x, double n){
    int i;
    double sum = 0;
    for ( i = 0; i <= n; i++)
    {
        sum += potencia(x, i)/fatorial(i);
    }
    return sum;
}

int main()
{
    double x;
    double n;
    do
    {
        scanf("%lf %lf", &n, &x);
        if (n == 0) break;
        printf("%.2f\n", exponencial(x, n));
    } while (1);
    
    return 0;
}
