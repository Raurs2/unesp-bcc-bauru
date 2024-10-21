#include <stdio.h>
#include <math.h>

int amigavel(int n1, int n2) {
    int i, sum1 = 0, sum2 = 0;
    for ( i = 1; i <= n1/2; i++)
        if (n1 % i == 0) sum1 += i;
    for ( i = 1; i <= n2/2; i++)
        if (n2 % i == 0) sum2 += i;
    if (sum1 == n2 && sum2 == n1) return 1;
    return 0;
}

int main() {
    int n1, n2;
    do
    {
        scanf("%d %d", &n1, &n2);
        if (n1 == 0 && n2 == 0) break;
        if (amigavel(n1, n2)) printf("eh\n");
        else printf("nao eh\n");
    } while (1);
    
    return 0;
}