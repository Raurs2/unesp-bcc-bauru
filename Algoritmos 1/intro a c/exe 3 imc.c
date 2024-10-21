#include<stdio.h>
int main()
{
    float peso, altura, imc;
    printf("Peso:\n");
    scanf("%f", &peso);
    printf("Altura:\n");
    scanf("%f", &altura);
    imc = peso / (altura * altura);
    printf("IMC: %f", imc);
    return 0;
}
