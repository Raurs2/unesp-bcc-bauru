#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int isMagicSquare(int a[MAX][MAX], int lin, int col) {
    int i, j, sumLin[lin], sumCol[lin], sumD[lin], d;
    if (lin == col)
    {
        for ( j = 0; j < lin; j++)
        {
            sumLin[j] = 0;
            sumCol[j] = 0;
            sumD[j] = 0;
        }
        for ( i = 0, d = lin-1; i < lin; i++, d--)
            for ( j = 0; j < col; j++)
            {
                sumLin[i] += a[i][j];
                sumCol[i] += a[j][i];
                if (j == i) sumD[0] += a[i][j];
                if (j == d) sumD[1] += a[i][j];
            } 
        for ( i = 0; i < lin; i++)
            if (sumD[0] != sumD[1] || sumLin[i] != sumCol[i]) return 0;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, n;
    int a[MAX][MAX];
    do
    {
        for ( i = 0; i < MAX; i++)
            for ( j = 0; j < MAX; j++)
                scanf("%d", &a[i][j]);
            
        if (isMagicSquare(a, MAX, MAX)) printf("e quadrado magico!\n");
        else printf("nao e quadrado magico!\n");
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}