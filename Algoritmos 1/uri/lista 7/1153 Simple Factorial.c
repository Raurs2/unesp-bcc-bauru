#include <stdio.h>
#include <math.h>

int main() {
    int n, i, f = 1;
    scanf("%d", &n);
    for ( i = 1; i <= n; i++)
    {
        f *= i;
    }
    printf("%d\n", f);
    return 0;    
}