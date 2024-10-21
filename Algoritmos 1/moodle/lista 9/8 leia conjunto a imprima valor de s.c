#include <stdio.h>

#define max 10

int main()
{
    double a[max], s;
    int  i, j;
    
    for ( i = 0; i < max; i++)
        scanf("%lf", &a[i]);
    for ( i = 0, j = max - 1; i <= max/2; i++, j--)
        s += (a[i] - a[j])*2;
    printf("%.2lf", s);
       
    return 0;
}
