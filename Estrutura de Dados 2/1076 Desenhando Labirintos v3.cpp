#include <cstdio>

int graph[100][100];
bool disc[100];

int moveCount(int n, int v)
{
    int moves = 0;
    disc[n] = true;
    
    for (int i = 0; i < v; i++)
        if (graph[n][i] && !disc[i])
            moves += moveCount(i, v) + 1; 

    return moves;
}

int main()
{
    int tests;

    scanf("%d", &tests);
    
    int n, v, a, x, y;

    while (tests--)
    {
        scanf("%d", &n);

        scanf("%d %d", &v, &a);

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
                graph[i][j] = 0;

            disc[i] = false;
        }
        
        while (a--)
        {
            scanf("%d %d", &x, &y);
            graph[x][y] = 1;
            graph[y][x] = 1;
        } 
        
        printf("%d\n", moveCount(n, v)*2);
    }
    
    return 0;
}
