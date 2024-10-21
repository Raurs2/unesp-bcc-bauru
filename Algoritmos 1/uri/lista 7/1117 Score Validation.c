#include <stdio.h>
#include <math.h>

int main() {
    double n1, n2, avr = 0, x = -1, y = -1;
    do
    {
        if (x != -1 && y != -1) break;
        scanf("%lf %lf", &n1, &n2);
        if (x > 0)
        {
            if (n1 < 0 || n1 > 10) {
            printf("nota invalida\n");
            
            } else y = n1;
        }
        if (x != -1 && y != -1) break;
        if (y > 0)
        {
            if (n2 < 0 || n2 > 10) {
            printf("nota invalida\n");
            
            } else x = n2;
        }
        if (x != -1 && y != -1) break;
        if (n1 < 0 || n1 > 10) {
            printf("nota invalida\n");
            
        } else x = n1;
        if (x != -1 && y != -1) break;
        if (n2 < 0 || n2 > 10) {
            printf("nota invalida\n");
            
        } else y = n2;
        if (x != -1 && y != -1) break;
    } while (x < 0 || y < 0);
    printf("media = %.2lf\n", (x+y)/2);
    
    return 0;    
}