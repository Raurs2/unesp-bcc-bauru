#include <stdio.h>
#include <math.h>

int main() {
    int n, i, x1, x2, x3, x4;
    scanf("%d", &n);
    for ( i = 1; i <= n; i++)
    {
        x1 = i*i;
        x2 = i*i*i;
        x3 = x1 + 1;
        x4 = x2 + 1;
        printf("%d %d %d\n", i, x1, x2);
        printf("%d %d %d\n", i, x3, x4);
    }
    
    return 0;    
}