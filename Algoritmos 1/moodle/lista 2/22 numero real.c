#include <stdio.h>
#include <math.h>
int main () {
    float n;

    printf("escreva numero real ");
    scanf("%f", &n);
    
    printf("\nParte inteira = %d", (int)n);
    printf("\nParte fracinaria = %.2f", n - (int)n);
    printf("\nArredondamento = %.2f", round(n));
}