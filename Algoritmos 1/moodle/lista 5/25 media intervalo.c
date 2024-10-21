#include <stdio.h>
#include <math.h>

int main()
{
    float avr = 0, i = 0,  n = 0;

    do
    {
        scanf("%f", &n);
        if (n >= 0)
        {
            avr += n;
            ++i;
        }
    } while (n >= 0);

    avr /= i;
    printf("MEDIA: %.2f\n", avr);
    return 0;
}