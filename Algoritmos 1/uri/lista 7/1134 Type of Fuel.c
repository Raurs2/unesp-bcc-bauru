#include <stdio.h>
#include <math.h>

int main() {
    int n, alco=0, gas=0, diesel= 0;
    do
    {
        scanf("%d", &n);
        if (n == 1) alco++;
        if (n == 2) gas++;
        if (n == 3) diesel++;
        
    } while (n != 4);
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", alco, gas, diesel);
    return 0;    
}