#include <stdio.h>
#include <stdlib.h>

#define max 8

int main()
{
    int n, i, j, lost;
    int a[max], b[max];

    do
    {
        for ( i = 0; i < max; i++)
            scanf("%d", &a[i]);
        
        for ( i = 0; i < max; i++)
            b[i] = a[i];
        
        for ( i = 0; i < max; i++)
        {
            for ( j = 1; j <= i; j++)
            {
                if (a[i] == a[j]) {
                    lost++;
                    b[j] = a[j+1];
                    b[i]
                }
            }
            
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
