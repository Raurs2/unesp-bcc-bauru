#include <stdio.h>
#include <stdlib.h>

#define max 3

int main()
{
    double a[max], b[max], s[max], sum;
    int  i, n;

    do
    {
        sum = 0;
        for ( i = 0; i < max; i++)
        {
            scanf("%lf", &a[i]);
            sum += a[i];
        }
            
        for ( i = 0; i < max; i++)
        {
            scanf("%lf", &b[i]);
            sum += b[i];
            s[i] = a[i] + b[i];
        }
        for ( i = 0; i < max; i++)
        {
            printf("%.0lf ", s[i]);
        }
        printf("Total = %.0lf", sum);
        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
           
    return 0;
}
