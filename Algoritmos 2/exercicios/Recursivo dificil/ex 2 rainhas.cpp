#include <stdio.h>

#define N 5

int isSafe(int board[N][N], int lin, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[lin][i]) return 0;            

    for (i = lin, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (i = lin, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return 0;
           
    return 1;
}

int nRainhasR(int board[N][N], int col)
{
    if (col >= N) return 1;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (nRainhasR(board, col + 1)) return 1;
            
            board[i][col] = 0;
        }   
    }
    return 0;
}

int nRainhas()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    if (!nRainhasR(board, 0))
    {
        printf("Sem solucao\n");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
        
    return 1;
    
}

int main()
{
    nRainhas();
    return 0;
}
