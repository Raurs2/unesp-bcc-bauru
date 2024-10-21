#include <stdio.h>
int main() {
    int m, n, x = 1, y = 1, maxX, maxY, calc, maxCalc = 0;
    scanf("%d %d", &m, &n);

    for ( x = 1; x <= m; x++)
    {
        for ( y = 1; y <= n; y++)
        {
            calc = x * y - x * x + y;
            if (calc > maxCalc)
            {
                maxX = x;
                maxY = y;
                maxCalc = calc;
            }
        }
    }
    
    printf("MAX CALC: %d\nMAX X: %d\nMAX Y: %d\n", maxCalc, maxX, maxY);
    
}