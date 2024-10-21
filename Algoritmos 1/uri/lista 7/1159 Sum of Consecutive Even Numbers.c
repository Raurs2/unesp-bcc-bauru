#include <stdio.h>
#include <math.h>

int main() {
    int n, sum = 0, y;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        y = 5;
        sum = 0;
        while (y != 0)
        {
            if (n % 2 == 0)
            {
                y--;
                sum += n;
            }
            n++;
        }
        printf("%d\n", sum);
        
    } while (1);
    
    
    return 0;    
}