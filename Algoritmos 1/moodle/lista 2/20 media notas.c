#include <stdio.h>
#include <math.h>
int main () {
    float n1, n2, n3, nFinal;

    printf("informe as 3 notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    nFinal = (n1 + n2 + n3)/3;

    printf("nota final = %.2f", nFinal);
}