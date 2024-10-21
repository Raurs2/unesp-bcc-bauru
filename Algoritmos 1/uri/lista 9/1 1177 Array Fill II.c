#include <stdio.h>

#define max 1000

int main()
{
    int i, j, a[max], n;
    scanf("%d", &n);
    
    for ( i = 0, j = 0; i < max; i++, j++)
    {
        if (j < n) a[i] = j;
        else {
            j = 0;
            a[i] = j;
        }
        printf("N[%d] = %d\n", i, a[i]);
    }
    
    return 0;
}
