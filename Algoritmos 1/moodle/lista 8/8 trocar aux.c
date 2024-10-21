#include <stdio.h>
#include <ctype.h>

int troca(float *n1, float *n2) {
    float aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int main() {
    float n1, n2;
    scanf("%f %f", &n1, &n2);
    printf("%f %f\n", n1, n2);
    troca(&n1, &n2);
    printf("%f %f\n", n1, n2);
    return 0;    
}