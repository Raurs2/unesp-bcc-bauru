#include <stdio.h>
#include <math.h>

int main() {
    int n, i, x, y, j, sum;
    scanf("%d", &n);
    for ( i = 1; i <= n; i++)
    {
        sum = 0;
        scanf("%d %d", &x, &y);
        while (y != 0)
        {
            if (x % 2 != 0)
            {
                y--;
                sum += x;
            }
            x++;
        }
        printf("%d\n", sum);
    }
    
    return 0;    
}