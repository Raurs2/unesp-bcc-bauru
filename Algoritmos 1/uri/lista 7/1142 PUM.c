#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, m;
    scanf("%d", &n);
    for ( i = 1, j = 1, m = 3; i <= n; i++, j += 1, m += 4)
    {
        for (j; j <= m; j++)
        {
            printf("%d ", j);
        }
        printf("PUM\n");
    }
    
    return 0;    
}