#include <stdio.h>
#include <math.h>

int main() {
    int n, i = 0;
    float avr = 0;
    do
    {
        scanf("%d", &n);
        
        if (n == 0) break;
        if (n % 2 != 0) continue;

        i++;
        avr += n;
    } while (n != 0);

    avr /= (float)(i);

    printf("media: %.2f", avr);

    return 0;    
}