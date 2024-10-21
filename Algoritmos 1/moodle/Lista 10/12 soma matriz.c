#include <stdio.h>
#define LIN 3
#define COL 3
int main() {
    int a[LIN][COL], i, j, sum = 0, k;
    do
    {
        
        for ( i = 0; i < LIN; i++)
        {
            for ( j = 0; j < COL; j++)
            {
                scanf("%d", &a[i][j]);
                sum += a[i][j];
            }
        }

        printf("tot = %d\n", sum);
        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}