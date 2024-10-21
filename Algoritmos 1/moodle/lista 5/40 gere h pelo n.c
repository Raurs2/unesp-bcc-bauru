#include <stdio.h>
#include <math.h>

int main()
{
    double j, s = 0, i, x;

    scanf("%lf", &x);

    for (j = 1.0, i = 1.0; j <= x; j++)
    {
        s +=  i / j;
        printf("%.2lf/%.2lf = %.2lf\n\n", i, j, s);
    }
    
    return 0;
}