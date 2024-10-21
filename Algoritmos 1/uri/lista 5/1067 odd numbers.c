#include <stdio.h>
#include <math.h>
int main() {
    int i, n, p = 0, o = 0, pos = 0, neg = 0;
    scanf("%d", &n);
    for ( i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d\n", i);
        }
        
    }
    return 0;
}