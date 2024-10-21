#include <stdio.h>
#include <math.h>

int main() {
    float sal, aumento;

    printf("informe o salario: ");
    scanf("%f", &sal);

    aumento = sal * 0.22 + sal;

    printf("imposto de renda = R$%.2f\n", aumento);
    return 0;
}