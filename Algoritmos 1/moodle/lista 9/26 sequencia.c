#include <stdio.h>
#include <stdlib.h>

#define max 100


int main()
{
    int i, n;
    int v[max], c = 0;

    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        if (v[i] != v[i-1]) c++;
    }
    printf("%d", c);

    return 0;
}
