#include <stdio.h>
#include <math.h>

int main() {
    int n, i, x, y, sum, aux;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &x, &y);
        if (x > y)
        {
            aux = y;
            y = x;
            x = aux;
        }
        
        for ( x += 1, sum = 0; x < y; x++)
        {
            if (x % 2 != 0) sum += x;
        }
        printf("%d\n", sum);
    }
    return 0;    
}