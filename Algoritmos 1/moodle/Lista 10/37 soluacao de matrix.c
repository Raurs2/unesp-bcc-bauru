#include <stdio.h>
#include <stdlib.h>

#define m 2
#define n 3

int main() {
    int i, j, n;
    float a[m][n], x[n], b[m];
    do
    {
        for ( i = 0; i < col; i++)
        {
            scanf("%f", &sum[i]);
        }
        
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                scanf("%f", &a[i][j]);
                a[i][j] *= sum[j];
            }
            
        }

        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                printf("%.1f ", a[i][j]);
            }
            printf("\n");
        }
        
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}