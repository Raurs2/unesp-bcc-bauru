#include <stdio.h>
#define max 3
int main() {
    int a[max][max], i, j, d = 0, k;
    do
    {
        scanf("%d", &k);
        for ( i = 0; i < max; i++, d++)
        {
            for ( j = 0; j < max; j++)
            {
                scanf("%d", &a[i][j]);
                if (j == i) a[i][j] *= k;
            }
        }
        for ( i = 0; i < max; i++)
        {
            for ( j = 0; j < max; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}