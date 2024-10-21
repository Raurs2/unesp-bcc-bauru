#include<stdio.h>
#define max 10

int main()
{
    int x[max], i, n;
    do
    {
        scanf("%d", &x[0]);
    } while (x[0] >= 50);
    
    for ( i = 1; i < max; i++)
        x[i] = 2 * x[i-1];

    for ( i = 0; i < max; i++)
         printf("N[%d] = %d\n", i, x[i]);

    return 0;
}