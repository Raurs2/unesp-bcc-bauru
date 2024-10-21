#include <stdio.h>
#include <stdlib.h>

#define max 100


int main()
{
    int i, n;
    int v[max], c = 1;

    do
    {
        c = 0;
        scanf("%d", &n);
        for ( i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }
        for ( i = 0; i < n-1; i++)
        {
            if (v[i] < v[i+1]) c++;
        }
        if (c == 0) c = 1;
        printf("%d", c);
    } while (n != 0);
    return 0;
}
