#include <stdio.h>
#include <math.h>

int main() {
    float i, ingresso, lucro, despesa = 200, j, maior;

    for (i = 5, j = 120; i <= 10; i += 0.50, j -= 26) {
        ingresso = i * j;
        lucro = ingresso - despesa;
        if (i == 5) maior = lucro;
        if (lucro > maior) maior = lucro;
        printf("%.2f - %.2f = %.2f\n", ingresso, despesa, lucro);
    }
    printf("\nMaior = %.2f\n", maior);
    
    return 0;    
}