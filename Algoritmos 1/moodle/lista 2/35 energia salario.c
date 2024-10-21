#include <stdio.h>
#include <math.h>

int main() {
    float sal, watts, qtdWatts;

    printf("informe o salario minimo e kilowatts mensal: ");
    scanf("%f %f", &sal, &qtdWatts);
    watts = sal/5;

    printf("Preco do quilowatt = R$%.2f\npreco a pagar = %.2f\nvalor com desconto = %.2f\n", watts, qtdWatts * watts, qtdWatts * watts-(qtdWatts * watts * 0.15));
    return 0;
}