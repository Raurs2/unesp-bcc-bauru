#include<stdio.h>
#define max 100

int main()
{
    int i;
    float x[max];

    for ( i = 0; i < max; i++)
        scanf("%f", &x[i]);

    for ( i = 0; i < max; i++)
        if (x[i] <= 10) printf("A[%d] = %.1f\n", i, x[i]);

    return 0;
}