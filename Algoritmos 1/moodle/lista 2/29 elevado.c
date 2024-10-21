#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2;

    printf("informe 2 numeros: ");
    scanf("%lf %lf", &x1, &x2);
    printf("potencia = %.2lf\n", pow(x1, x2));
    return 0;
}