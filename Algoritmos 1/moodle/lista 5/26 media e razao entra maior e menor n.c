#include <stdio.h>
#include <math.h>

int main()
{
    float avr = 0, i = 0,  n = 0, big, small;

    do
    {
        scanf("%f", &n);

        if (n >= 0)
        {
            avr += n;
            ++i;

            if (i == 1)
            {
                big = n;
                small = n;
            }
            
            if (n > big)
            {
                big = n;
            } else  if (n < small && n >= 0){
                small = n;
            }
        }        
    } while (n >= 0);

    avr /= i;
    printf("MEDIA: %.2f\nRAZAO: %.2f", avr, big/small);
    return 0;
}