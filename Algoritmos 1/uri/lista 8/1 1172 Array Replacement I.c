#include<stdio.h>
#define max 10

int main()
{
    int x[max], i;
    
    for ( i = 0; i < max; i++)
        scanf("%d", &x[i]);
    
    for ( i = 0; i < max; i++)
        if (x[i] <= 0) x[i] = 1;

    for ( i = 0; i < max; i++)
         printf("X[%d] = %d\n", i, x[i]);

    return 0;
}