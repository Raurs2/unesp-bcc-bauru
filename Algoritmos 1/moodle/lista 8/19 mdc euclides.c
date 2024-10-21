#include <stdio.h>
#include <math.h>

void troca(int *n1, int *n2) {
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int mdc(int n1, int n2) {
    int r;
    do
    {
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    } while (n2 != 0);
    return n1;
}

int main() {
    int n1, n2, r;
    scanf("%d %d", &n1, &n2);
    if (n2 > n1) troca(&n1, &n2);
    printf("MDC = %d", mdc(n1, n2));
    return 0;    
}