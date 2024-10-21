#include <stdio.h>
#include <math.h>

int main() {
    double sal, salMin;

    printf("informe o salario e o salario minimo: ");
    scanf("%lf %lf", &sal, &salMin);

    printf("funcionario ganha  = %.2lf salarios minimos\n", sal / salMin);
    return 0;
}