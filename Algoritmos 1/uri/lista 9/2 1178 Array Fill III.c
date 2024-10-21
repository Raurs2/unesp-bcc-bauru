#include <stdio.h>

#define max 100

int main()
{
    int i;
    double a[max];
    scanf("%lf", &a[0]);
    
    for ( i = 0; i < max; i++)
    {
        if (i > 0) a[i] = a[i-1]/2; 
        printf("N[%d] = %.4lf\n", i, a[i]);
    }
    
    return 0;
}
