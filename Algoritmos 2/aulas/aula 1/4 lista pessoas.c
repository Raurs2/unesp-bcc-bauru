#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20], ende[20];
    int telefone;
} registro;

int main()
{
    registro lista[31], aux;
    int n, tot = 0, i, j;
    while (1)
    {
        scanf("%s", &lista->nome);
        fflush (stdin);
        scanf("%s", &lista->ende);
        fflush (stdin);
        scanf("%d", &lista->telefone);
        fflush (stdin);
        scanf("%d", &n);
        fflush (stdin);
        tot++;
        if (n == 0) break;
    }

    for(i = 0 ; i < tot-1 ; i++) 
    for(j = i + 1 ; j < tot; j++)
      if(strcmp(lista[i].nome, lista[j].nome) > 0) {
      aux = lista[i];
      lista[i] = lista[j];
      lista[j] = aux;
    }

    for ( i = 0; i < tot; i++)
    {
        printf("%s\n", lista[i].nome);
    }
    
    
    return 0;
}
