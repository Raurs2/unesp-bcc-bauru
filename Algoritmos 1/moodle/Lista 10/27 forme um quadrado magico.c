#include <stdio.h>
#include <stdlib.h>

#define n 3

int isMagicSquare(int a[n][n], int lin, int col) {
    int i, j, square = 0, sumLin[lin], sumCol[lin], sumD[lin], d;
    if (lin == col)
    {
        for ( j = 0; j < lin; j++)
        {
            sumLin[j] = 0;
            sumCol[j] = 0;
            sumD[j] = 0;
        }
        for ( i = 0, square = 1, d = lin-1; i < lin; i++, d--)
            for ( j = 0; j < col; j++)
            {
                sumLin[i] += a[i][j];
                sumCol[i] += a[j][i];
                if (j == i) sumD[0] += a[i][j];
                if (j == d) sumD[1] += a[i][j];
                
            } 
        for ( i = 0; i < lin; i++)
            if (sumD[0] != sumD[1] || sumLin[i] != sumCol[i]) square = 0;
    }
    return square;
}

int main() {
    int M[n][n], i, j;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    if (isMagicSquare(M, n, n)) printf("eh quad magico\n");
    else printf("n eh quad magico\n");
    return 0;
}