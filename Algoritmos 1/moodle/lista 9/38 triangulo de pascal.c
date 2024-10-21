#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

void fatorial(double x, double * fat){
    *fat = 1;
    for (x; x > 0; x--)
        *fat *= x;
}

int main()
{
    int i, j, a[max], n, b[max];
    do
    {
        scanf("%d", &n);
        for ( i = 0, j = 1; i < n; i++)
        {
            a[i] = i;
            for ( j = 0; j < n; j++)
            {
                b[i] = i*j
            }
            
        }
        
        
        

    } while (n != 0);
    return 0;
}
