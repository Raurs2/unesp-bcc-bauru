#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 50

int main()
{
    int a[max];
    int  i, n, r;

    do
    {
        srand(time(NULL));
        for ( i = 0; i < max; i++)
        {
            a[i] = rand() % 230 + 120;
        }

        for ( i = 0; i < max; i++)
        {
            printf("%d ", a[i]);
        }
        
        
        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
           
    return 0;
}
