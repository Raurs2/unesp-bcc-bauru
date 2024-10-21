#include <stdio.h>
#include <math.h>
int main () {
    float n, j, r;

    printf("deposito ");
    scanf("%f", &n);
    printf("Juros em decimal 0.1 = 10 porcento");
    scanf("%f", &j);

    r = n + (j * n);

    printf("rendimento = %.2f", r);
}