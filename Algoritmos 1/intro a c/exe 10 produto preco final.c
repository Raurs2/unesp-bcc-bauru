#include<stdio.h>
int main()
{
    float custo, final, imposto, lucro;
    printf("Custo: ");
    scanf("%f", &custo);
    imposto = custo * 0.45;
    lucro = custo * 0.5;
    final = custo + imposto + lucro;
    printf("Final: R$%.2f", final);
    return 0;
}
