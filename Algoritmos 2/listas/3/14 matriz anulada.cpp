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
    
    int n, m, a;
    fscanf(arq, "%d %d %d", &n, &m, &a);

    int v[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = 1;
    
    int x, y;
    for (int i = 0; i < a; i++)
    {
        fscanf(arq, "%d %d", &x, &y);
        v[x][y] = 0;
    }

    fclose(arq);
    
   if ((arq = fopen("matriz_nova.txt", "wt")) == NULL)
    {
        printf("ARQUIVO N ABERTO\n");
        exit(1);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(arq, "%d ", v[i][j]);
            //printf("%d", v[i][j]);
        }
        fprintf(arq, "\n");
        //printf("\n");
    }
    fclose(arq);

    printf("cabo\n");

    return 0;
}
