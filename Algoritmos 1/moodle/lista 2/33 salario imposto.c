#include <stdio.h>
#include <math.h>

int main() {
    float sal, imposto;

    printf("informe o salario: ");
    scanf("%f", &sal);

    imposto = sal * 0.05;

    printf("imposto de renda = R$%.2f\n", imposto);
    return 0;
}