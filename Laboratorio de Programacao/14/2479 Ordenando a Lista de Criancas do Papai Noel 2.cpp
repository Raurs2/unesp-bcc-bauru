#include <stdio.h>
#include <string.h>
#define max 100

int Organiza(const void *v1, const void *v2)
{
    return (strcmp((char*) v1, (char*) v2));
}

int main ()
{
    int N, Comportadas = 0, Tamanho, i, j;
    char Sinal, Nomes[max][21];
    scanf("%d\n", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%c \n", &Sinal);
        fgets(Nomes[i], sizeof(Nomes[i]), stdin);
        if(Sinal == '+')
        {
            Comportadas++;
        }
    }
    qsort(Nomes, N, sizeof(Nomes[0]), Organiza);
    for(i = 0; i < N; i++)
    {
        printf("%s", Nomes[i]);
        Tamanho = strlen(Nomes[i]);
        if(Nomes[i][Tamanho - 1] != '\n')
        {
            printf("\n");
        }
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n", Comportadas, N - Comportadas);
    return 0;
}