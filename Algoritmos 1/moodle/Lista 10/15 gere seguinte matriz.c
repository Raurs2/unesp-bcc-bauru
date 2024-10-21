#include <stdio.h>
#define LIN 6
#define COL 6
int main() {
    int a[LIN][COL], i, j, sum = 0, k, b[LIN][COL], c[LIN][COL];
    do
    {
        
        for ( i = 0; i < LIN; i++)
        {
            for ( j = 0; j < COL; j++)
            {
                if (i == 0 || i == 5 || j == 0 || j == 5) a[i][j] = 1;
                else if ( i == 4 || i == 1 && j != 0 && j != 5 || j == 1 || j == 4) a[i][j] = 2;
                else if (i == 2 || i == 3 && j > 1 && j < 4 || j == 2 || j == 3) a[i][j] = 3;
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}