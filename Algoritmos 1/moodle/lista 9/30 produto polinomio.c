#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int main()
{
    int i, j, a[max], n, b[max];
    do
    {
        scanf("%d", &n);
        srand(time(NULL));
        for ( i = 0; i < n; i++)
        {
            b[i] = 0;
            a[i] = rand() % 10 + 1;
            printf("%d ", a[i]);
        }
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < n; j++)
            {
                if (a[i] == a[j]) b[i]++;
            }
            
        }
        printf("\n");
        for ( i = 0; i < n; i++)
        {
            printf("%d* %d\n", a[i], b[i]);
        }
        
        
        

    } while (n != 0);
    return 0;
}
