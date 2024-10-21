#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float x, y;

    scanf("%d", &n);
    do
    {
        scanf("%f %f", &x, &y);
        if (y == 0) printf("divisao impossivel\n");
        else printf("%.1f\n", x/y);
        n--;
    } while (n > 0);
    
    return 0;    
}