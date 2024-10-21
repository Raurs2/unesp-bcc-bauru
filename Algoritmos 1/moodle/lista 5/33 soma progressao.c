#include <stdio.h>
#include <math.h>

int main()
{
    float i, j, s = 0;

    for (i = 38, j = 1; j <= 37; i--, j++)
    {
        s += (i-1) * i / j;
        printf("%.2f/%.2f = %.2f\n", (i-1) * i, j, s);
    }

    return 0;
}