#include <stdio.h>
#include <math.h>
int main () {
    int a, b;

    printf("Digite 2 inteiros: ");
    scanf("%d %d", &a, &b);

    printf("soma = %d\n", a + b);
    printf("subtracao primeiro pelo ultimo= %d\n", a - b);
    printf("subtracao ultimo pelo primeiro = %d\n", b - a);
    printf("multiplicacao = %d\n", a * b);
    printf("Divisao do primeiro pelo segundo= %f\n", a / (float)b);
    printf("divisao do segundo pelo primeiro = %f\n", b / (float)a);
    printf("quociente inteiro da divisão do primeiro pelo segundo = %d\n", a/b);
    printf("quociente inteiro da divisão do segundo pelo primeiro = %d\n", b/a);
    printf("resto da divisão do primeiro pelo segundo = %d\n", a%b);
    printf("resto da divisão do segundo pelo primeiro = %d\n", b&a); 
}