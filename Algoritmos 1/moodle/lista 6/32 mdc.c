#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n1, n2, aux, r;
    scanf("%d %d", &n1, &n2);
    
    if (n2 > n1)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    
    do
    {
        r = n1 % n2;
            n1 = n2;
            n2 = r;

    } while (n2 != 0);
    printf("MDC = %d", n1);
    return 0;    
}