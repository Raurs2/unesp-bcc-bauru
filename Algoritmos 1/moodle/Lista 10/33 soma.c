#include <stdio.h>
#include <stdlib.h>

#define lin 2
#define col 3

int main() {
    int i, j, n;
    float a[lin][col], sum[lin];
    do
    {
        for ( i = 0; i < lin; i++)
        {
            sum[i] = 0;
        }
        
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                scanf("%f", &a[i][j]);
                sum[i] += a[i][j];
            }
            
        }

        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                printf("%.1f ", a[i][j]);
            }
            printf(" = %.1f\n", sum[i]);
        }
        
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}