#include <stdio.h>
#define LIN 3
#define COL 3
int main() {
    int a[LIN][COL], i, j, sum = 0, k, b[LIN][COL], c[LIN][COL];
    do
    {
        
        for ( i = 0; i < LIN; i++)
        {
            for ( j = 0; j < COL; j++)
            {
                scanf("%d", &a[i][j]);
                scanf("%d", &b[i][j]);
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        for ( i = 0; i < LIN; i++)
        {
            for ( j = 0; j < COL; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
        
        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}