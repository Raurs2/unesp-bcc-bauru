#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;

    scanf("%d", &n);

    for (i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", n, i, n*i);
    }
    return 0;
}