#include <stdio.h>
#define LIN 20
#define COL 50
int main() {
    int a[LIN][COL], i, j, k, b[LIN][COL], lin, col;
    do
    {
        scanf("%d %d", &lin, &col);
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                scanf("%d", &a[i][j]);
                b[j][i] = a[i][j];
            }
            
        }
        printf("\n");
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for ( i = 0; i < col; i++)
        {
            for ( j = 0; j < lin; j++)
            {
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}