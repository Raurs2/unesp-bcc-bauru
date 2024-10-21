#include <stdio.h>
#include <math.h>

void troca(int *n1, int *n2) {
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int multi(int n1, int n2) {
    int r = 0;
    do
    {
        if (n1 % 2 != 0) r += n2;
        n1 /= 2;
        n2 *= 2;
        if (n1 == 1) r += n2;
    } while (n1 != 1);
    return r;
}

int main() {
    int n1, n2, r;
    scanf("%d %d", &n1, &n2);
    if (n2 > n1) troca(&n1, &n2);
    printf("x = %d", multi(n1, n2));
    return 0;    
}