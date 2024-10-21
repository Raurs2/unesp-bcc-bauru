#include <stdio.h>
#include <stdlib.h>

#define LIN 50
#define COL 50

int main() {
    int a[LIN][COL], i, j, k, b[LIN][COL], lin, col, simetria = 1;
    do
    {
        simetria = 1;
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
                if (b[i][j] != a[i][j]) simetria = 0; 
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
        if (simetria) printf("\neh simetrica");
        else printf("\nn eh simetrica");
        printf("\nContinuar != 0\n");
        scanf("%d", &k);
        system("cls");
    } while (k != 0);
    
}