#include <stdio.h>
#include <math.h>
int main() {
    int p = 0, i;
    float avr, n, s = 0;
    for ( i = 0; i < 6; i++)
    {
        scanf("%f", &n);
        if (n > 0)
        {
            s += n;
            p += 1;
        }
    }
    avr = s/p;
    printf("%d valores positivos\n%.1f\n", p, avr);
    return 0;
}