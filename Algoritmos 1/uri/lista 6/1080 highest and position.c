#include <stdio.h>

int main()
{
    int n, i, high = 0, pos;

    for (i = 1; i <= 100; i++)
    {
        scanf("%d", &n);

        if (n > high)
        {
            high = n;
            pos = i;
        }
    }

    printf("%d\n%d\n", high, pos);
    return 0;
}
