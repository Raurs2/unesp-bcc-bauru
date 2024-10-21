#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, i, x;

    scanf("%lf", &x);

    for (j = 1.0, i = 0.0; j <= x; j++, i++)
    {
        s +=  j / (x - i);
        printf("%.2lf/%.2lf = %.2lf\n\n", j, (x - i), s);
    }
    
    return 0;
}