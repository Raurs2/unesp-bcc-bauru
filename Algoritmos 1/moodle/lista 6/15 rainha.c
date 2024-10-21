#include <stdio.h>
#include <math.h>

int main() {
    int i;
    double pagar = 1;
    for (i = 2; i <= 64; i++)
    {
        pagar *= 2;
    }
    printf("%.1lf", pagar);
    
    return 0;    
}