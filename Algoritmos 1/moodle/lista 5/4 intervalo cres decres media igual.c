#include <stdio.h>
#include <math.h>
int main() {
    int n1, n2, tot = 0, aux;
    float avr;
    scanf("%d %d", &n1, &n2);
    if (n1 > n2)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    } else if (n1 == n2)
    {
        printf("Iguais\n");
    }
    aux = n2 - n1 + 1;
    for (n1; n1 <= n2; n1++)
    {
        tot += n1;
    }
    avr = (float)tot/aux;
    printf("Media: %.2f\n", avr);
    return 0;
}