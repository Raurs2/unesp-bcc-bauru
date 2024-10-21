#include <stdio.h>
#include <math.h>

double fatorial(double f){
    double fat = 1, i;

    if (f == 0) return fat;
    
    for (i = 1; i <= f; i++)
    {
        fat *= i;
    }
    return fat;
}


int main() {
    double e, x, n, i;

    scanf("%lf %lf", &x, &n);

    for (i = 0; i <= n; i++)
    {
        e += pow(x, i)/fatorial(i);
    }
    
    printf("EXP(X) = %.2lf\nMath = %.2lf", e, exp(x));
    return 0;    
}