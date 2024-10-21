#include <stdio.h>
#include <math.h>

int main() {
    float n, i = 0, avr = 0;
    
    do
    {
        scanf("%f", &n);
        if (n < 0) break;
        avr += n;
        i++;
    } while (n >= 0);
    printf("%.2f\n", avr/i);
    return 0;    
}