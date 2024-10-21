#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int isPermutacao(int a[MAX][MAX], int lin, int col) {
    int i, j, ones = 0, zeros = 0, moreOne = 0, k;
    if (lin == col)
    {
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0, zeros = 0, moreOne = 0, ones = 0; j < col; j++)
            {
                if (a[i][j] == 0) zeros++;
                if (a[i][j] == 1) {
                    ones++;
                    for ( k = i+1; k < lin; k++)
                        if (a[k][j] == 1) moreOne = 1;
                }
            }
            if (zeros + ones > lin || moreOne || ones != 1 || zeros != lin-1) return 0;
        }
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
            
        if (isPermutacao(a, MAX, MAX)) printf("e permutacao!\n");
        else printf("nao e permutacao!\n");
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}