#include <stdio.h>
#include <math.h>

int main() {
    int x, y, sum, aux;
    do
    {
        scanf("%d %d", &x, &y);
        if (x <= 0 || y <= 0) break;
        if (x > y)
        {
            aux = y;
            y = x;
            x = aux;
        }
        for ( x, sum = 0; x <= y; x++)
        {
            sum += x;
            printf("%d ", x);
        }
        printf("Sum=%d\n", sum);
        
    } while (1);
    
    return 0;    
}