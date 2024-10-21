#include <stdio.h>
#include <math.h>
int main () {
    float n1, n2, nFinal, p1, p2;

    printf("informe as 2 notas:\n");
    scanf("%f %f", &n1, &n2);
    
    printf("informe os respectivos pesos:\n");
    scanf("%f %f", &p1, &p2);

    nFinal = (n1*p1 + n2*p2)/ (p1+p2);

    printf("nota final = %.2f", nFinal);
}