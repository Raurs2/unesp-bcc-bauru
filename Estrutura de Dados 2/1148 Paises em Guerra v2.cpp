#include <cstdlib>
#include <cstdio>

#define MAX 999999999
#define max 501
 
int g[max][max], vertices;
 
int dijkstra(int origem, int destino) 
{
    int min, atual;
    int passou[max], pred[max],custo[max];

    for (int i = 1; i <= vertices; i++) 
    {
        pred[i]=-1;
        custo[i]=MAX;
        passou[i]=0;
    }

    custo[origem] = 0;
    atual = origem;

    while (atual != destino)
    {
        for (int i = 1; i <= vertices;  i++) 
        {
            if (custo[i] > custo[atual] + g[atual][i]) 
                custo[i] = custo[atual] + g[atual][i];
        }

        min = MAX;
        passou[atual] = 1;

        for (int i = 1; i <= vertices; i++) 
        {
            if ((custo[i] < min) && (!passou[i]))
            {
                min = custo[i];
                atual = i;
            }
        }

        if (min == MAX) return MAX;
    }
    return custo[destino];
}
 
int main() 
{
    int arestas, origem, destino, peso, consultas;

    scanf("%d %d", &vertices, &arestas);

    while (vertices || arestas)
    {
 
        for (int i = 1; i <= vertices; i++) 
            for (int j = 1;j <= vertices; j++) 
                g[i][j]=MAX;

        for (int i = 1; i <= arestas; i++)
        {
            scanf("%d %d %d", &origem, &destino, &peso);

            g[origem][destino] = peso;

            if (g[destino][origem] != MAX)
            {
                g[origem][destino] = 0;
                g[destino][origem] = 0;
            }
        }

        scanf("%d", &consultas);

        for (int i = 1; i <= consultas; i++)
        {
            scanf("%d %d", &origem, &destino);
 
            if (dijkstra(origem,destino)== MAX)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dijkstra(origem, destino));
        }

        scanf("%d %d", &vertices, &arestas);
        printf("\n");
    }

    return 0;
}