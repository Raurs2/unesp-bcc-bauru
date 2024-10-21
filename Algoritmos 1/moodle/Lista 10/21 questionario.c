#include <stdio.h>

int main() {
    int i, j, n, pergunta[10][5], k = 0;
    for ( i = 0; i < 10; i++)
            for ( j = 0; j < 5; j++)
                pergunta[i][j] = 0;
    do
    {
        
        
        for ( i = 0; i < 10; i++)
        {
            printf("Pergunta %d\n", i+1);
            scanf("%d", &n);
            if (n == 1) pergunta[i][0]++;
            else if (n == 2) pergunta[i][1]++;
            else if (n == 3) pergunta[i][2]++;
            else if (n == 4) pergunta[i][3]++;
            else if (n == 5) pergunta[i][4]++;
        }
        k++;
        printf("Continuar != 0\n");
        scanf("%d", &n);
    } while (n != 0);
    printf("\nResponderam: %d pessoas\n", k);
    printf(" respostas: 1 2 3 4 5\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d pergunta: ", i+1);
        for ( j = 0; j < 5; j++)
        {
            printf("%d ", pergunta[i][j]);
        }
        printf("\n");
    }
    return 0;
}