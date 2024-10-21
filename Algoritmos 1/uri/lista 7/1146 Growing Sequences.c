#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    do
    {
        scanf("%d",&n);
        if (n == 0) break;
        for ( i = 1; i <= n; i++)
        {
            printf("%d", i);
            if (i < n) printf(" ");
        }
        printf("\n");
    } while (n != 0);
    
    
    return 0;    
}