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
            a[i] = rand() % 50 + 1;
        }
        scanf("%d", &r);

        for ( i = 0; i < max; i++)
        {
            if (r == a[i]) printf("Tem chave\n");
        }
        
        
        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
           
    return 0;
}
