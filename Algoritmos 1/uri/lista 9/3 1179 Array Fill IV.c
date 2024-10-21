#include <stdio.h>

#define max 5

int main()
{
    int i, j, k;
    int par[max], impar[max], n;
    for ( i = 0, j = 0, k = 0; i < 15; i++)
    {
        scanf("%d", &n);
        if (n%2) {
            if (k > 4) {
                for ( k = 0; k < 5; k++)
                {
                    printf("impar[%d] = %d\n", k, impar[k]);
                }
                
                k = 0;
            }
            impar[k] = n;
            k++;
        } else {
            if (j > 4) {
                for ( j = 0; j < 5; j++)
                {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                j = 0;
            }
            par[j] = n;
            j++;
            
        }
    }
    for ( i = 0; i < k; i++)
    {
        printf("impar[%d] = %d\n", i, impar[i]);
    }
    for ( i = 0; i < j; i++)
    {
        printf("par[%d] = %d\n", i, par[i]);
    }
    
    
    
    return 0;
}
