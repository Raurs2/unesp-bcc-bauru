#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Raul Alexandre Gonzalez Augusto

typedef struct no_pilha
{
    int safra;
    char nome[30];
    struct no_pilha *prox;
} No;

typedef struct descritor{
	    int quantidade;
      	No *pilha;
        } def_pilha;

int vazia(def_pilha pilha){
 	return(pilha.pilha==NULL);
}

No* cria_no(int safrap, char nomep[])
{	
    No* q = (No*) malloc(sizeof(struct no_pilha));
    q->safra=safrap;
    strcpy(q->nome, nomep);
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* pilha, int safrap, char nomep[30])
{
    No* q = cria_no(safrap, nomep);
    if(!vazia(*pilha)) q->prox = pilha->pilha;
    pilha->pilha = q;
    pilha->quantidade++;
}

int desempilha(def_pilha* pilha, int* safrap, char nomep[30])
{
	No* q;

    if (pilha->pilha==NULL) return 0;

    q = pilha->pilha;
    *safrap = q->safra;
    strcpy(nomep, q->nome);

    pilha->pilha = pilha->pilha->prox;
    free(q);
    pilha->quantidade--;

    return 1;
}

void visualiza(def_pilha pilha)
{
    while (pilha.pilha != NULL)
    {
          printf("Nome: %s\nSafra de: %d\n", pilha.pilha->nome, pilha.pilha->safra);
          pilha.pilha=pilha.pilha->prox;
    }
    printf("\n");
}


int main()
{
   int safrap, op, oldest[5], i;
   char nomep[30], oldestName[5][30];

   def_pilha pilha;
   pilha.pilha = NULL;
   pilha.quantidade = 0;

    for ( i = 0; i < 5; i++)
    {
        oldest[i] = 99999;
    }
    
    do
    {
        do
        {
            printf("1 - incluir\n2 - abrir vinho\n3 - 5 vinhos mais antigos\n4 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 4);

        if (op == 1)
        {
            printf("Safra: ");
            scanf("%d", &safrap);

            getchar();

            printf("Nome: ");
            scanf("%s", &nomep);

            empilha(&pilha, safrap, nomep);

            for ( i = 0; i < 5; i++)
            {
                if (safrap < oldest[i])
                {
                    oldest[i] = safrap;
                    strcpy(oldestName[i], nomep);
                    break;
                }
            }
        } else if (op == 2)
        {

            if (desempilha(&pilha, &safrap, nomep))
            {
                printf("Deve abrir %s da safra de %d\nRestantes: %d\n", nomep, safrap, pilha.quantidade);
                for ( i = 0; i < 5; i++)
                {
                    if (safrap == oldest[i])
                    {
                        oldest[i] = 99999;
                    }
                    
                }
                
            } else printf("Acabou o estoque");
        } else if (op == 3)
        {
            printf("Mais velhos:\n");
            for ( i = 0; i < 5; i++)
            {
                if (oldest[i] != 99999)
                {
                    printf("Vinho %s da safra de %d\n", oldestName[i], oldest[i]);
                }
            }
        }
        
    } while (op != 4);

   return 1;
}
