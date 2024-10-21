#include <stdio.h>
#define max 3
int main() {
    int a[max][max], i, j, lin[max], sum = 0, k;
    do
    {
        for ( i = 0; i < max; i++)
        {
            lin[i] = 0;
        }
        
        for ( i = 0; i < max; i++)
        {
            for ( j = 0; j < max; j++)
            {
                scanf("%d", &a[i][j]);
                lin[i] += a[i][j];
                sum += a[i][j];
            }
        }
        for ( i = 0; i < max; i++)
        {
            printf("Lin %d = %d\n", i, lin[i]);
        }
        printf("tot = %d\n", sum);
        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}