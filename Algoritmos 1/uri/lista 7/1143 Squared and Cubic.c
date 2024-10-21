#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, m, r = 1;
    scanf("%d", &n);
    for ( i = 1, m = 1; i <= n; i++, m++, r = 1)
    {
        for (j = 1; j <= 3; j++)
        {
            r *= m;
            printf("%d", r);
            if (j <= 2) printf(" ");
        }
        printf("\n");
    }
    
    return 0;    
}