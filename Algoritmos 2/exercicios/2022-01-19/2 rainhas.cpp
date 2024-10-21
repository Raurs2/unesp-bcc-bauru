#include<stdio.h>

#define MAX 100

int main()
{
    int n, chessboard[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            chessboard[i][j] = 0;
    return 0;
}
