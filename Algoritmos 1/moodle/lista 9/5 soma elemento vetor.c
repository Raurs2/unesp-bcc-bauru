#include <stdio.h>
#include <stdlib.h>

#define max 4

int main()
{
    int n, i, sum = 0;
    int a[max];

    do
    {
        sum = 0;
        for ( i = 0; i < max; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        printf("Soma = %d", sum);
        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
