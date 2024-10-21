#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n, i, sum = 0;
    do
    {
        scanf("%d", &n);
        if (n == -1) break;
        for ( i = 1, sum = 0; i < n; i++)
            if (n % i == 0) sum += i;
        if (sum == n) printf("perfeito\n");
        else printf("n eh\n");
        
    } while (1);
    
    return 0;    
}