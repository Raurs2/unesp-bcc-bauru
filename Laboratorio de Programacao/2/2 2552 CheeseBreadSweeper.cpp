#include <stdio.h>

#define MAX 101

/*

*/

int main()
{
    int n, m, v[MAX][MAX], x, sum;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &x);
                if (x) v[i][j] = 9;
                else v[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0, sum = 0; j < m; j++)
            {
                sum = 0;
                if (v[i][j] == 0)
                {
                    if (i > 0 && v[i - 1][j] == 9) sum++;
                    if (i < n-1 && v[i + 1][j] == 9) sum++;
                    if (j > 0 && v[i][j - 1] == 9) sum++;
                    if (j < m-1 && v[i][j + 1] == 9) sum++;
                    v[i][j] = sum;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d", v[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
