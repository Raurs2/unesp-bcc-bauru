#include <stdio.h>
#include <math.h>
int main() {
    int n, i, j, m;
    scanf("%d", &n);
    m = n;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("%d ", j);
        }
        m -= 1;
        printf("\n");
    }
    
    
    return 0;
}