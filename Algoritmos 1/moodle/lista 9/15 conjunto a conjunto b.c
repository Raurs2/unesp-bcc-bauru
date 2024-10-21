#include <stdio.h>
#include <stdlib.h>

#define max 80

int main()
{
    int n, i;
    float a[max], b[max];

    do
    {
        for ( i = 0; i < max; i++)
            scanf("%f", &a[i]);
        
        for ( i = 0; i < max; i++)
        {
            if ((int)a[i] % 2 == 0) b[i] = a[i]/2;
            else b[i] = a[i]*3;
            printf("%.2f ", a[i]);
        }
        printf("\n");
        for ( i = 0; i < max; i++)
            printf("%.2f ", b[i]);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
