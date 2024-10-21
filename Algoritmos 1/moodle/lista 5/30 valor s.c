#include <stdio.h>
#include <math.h>

int main()
{
    float i, j, s = 0;

    for (i = 1, j = 1; i < 99; i += 2, j++)
    {
        s += i/j;
        printf("%.2f/%.2f = %.2f\n", i, j, s);
    }

    return 0;
}