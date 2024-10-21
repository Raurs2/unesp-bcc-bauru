#include <stdio.h>
#include <stdlib.h>

#define maxA 10
#define maxB 20
#define maxX 30


int main()
{
    int i, n, j, k, l, test, d, ini;
    int a[maxA], b[maxB], x[maxX], y[maxB], z[maxA], e[maxB];

    do
    {
        k = l = d = ini = 0;
        for ( i = 0; i < maxA; i++)
        {
            scanf("%d", &a[i]);
            x[i] = a[i];
        }
        for ( i = 0; i < maxB; i++)
        {
            scanf("%d", &b[i]);
            for ( j = 0; j < maxA; j++)
            {
                if (b[i] == a[j]) {
                    y[k] = b[i];
                    test = 0;
                    k++;
                } else if (b[i] != a[j]) test = 1;
            }
            if (test == 1)
            {
                e[d] = b[i];
                d++;
            }
            
            
        }
        
        for ( i = 0; i < maxA; i++)
        {
            for ( j = 0; j < k; j++)
            {
                if (a[i] != y[j]) test = 1;
                else test = 0;
            }
            if (test == 1) {
                z[l] = a[i];
                l++;
            }
            
        }
        
        for ( i = 0; i < l; i++, ini++)
        {
            x[ini] = z[i];
        }
        for ( i = 0; i < d; i++, ini++)
        {
            x[ini] = e[i];
        }
        for ( i = 0; i < k; i++, ini++)
        {
            x[ini] = b[i];
        }
        
        
        printf("X\n");
        for ( i = 0; i < maxX; i++)
            printf("%d ", x[i]);
        printf("\n");
        printf("Y\n");
        for ( i = 0; i < maxB; i++)
            printf("%d ", y[i]);
        printf("\n");
        printf("Z\n");
        for ( i = 0; i < maxA; i++)
            printf("%d ", z[i]);
        printf("\n");

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
