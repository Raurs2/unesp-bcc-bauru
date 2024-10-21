#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 30

int main()
{
    FILE *arq;

    char file_name[max] = "matriz.txt";
    if ((arq = fopen(file_name, "rt")) == NULL)
    {
        printf("ARQUIVO N ABERTO\n");
        exit(1);
    }
    
    int n, m;
    fscanf(arq, "%d %d", &n, &m);

    int v[n][m];

    
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(arq, "%d", &x);
            v[i][j] = x;
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    fclose(arq);

    return 0;
}
