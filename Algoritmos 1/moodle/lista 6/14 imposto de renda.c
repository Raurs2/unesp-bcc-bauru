#include <stdio.h>
#include <math.h>

int main() {
    int cpf, depende;
    float renda, minSalary, desconto, imposto;

    scanf("%f", &minSalary);

    do
    {
        scanf("%d %d %f", &cpf, &depende, &renda);
        if (cpf < 0) break;

        if (renda <= 2 * minSalary){
            printf("Isento\n\n");
            continue;
        }   else if (renda <= 3 && renda > 2) imposto = renda * 0.05;
                else if (renda <= 5 && renda > 3) imposto = renda * 0.1;
                    else if (renda <= 7 && renda > 5) imposto = renda * 0.15;
                        else if (renda > 7) imposto = renda * 0.20;

        desconto = minSalary * 0.05 * depende;
        if (desconto > imposto) imposto = 0;

        imposto -= desconto;

        printf("%d\nBruto: %.2f$\nImposto: %.2f$\nLiquido: %.2f$\n\n", cpf, renda, imposto, renda - imposto);
    } while (cpf > 0);
    
    return 0;    
}