#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 100

/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

typedef struct no_pilha
{
    char str;
    struct no_pilha *prox;
} *def_pilha;

def_pilha cria_no( char strp)
{	
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));
    q->str = strp;
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* pilha, char strp)
{
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));

    q->str = strp;
    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, char strp)
{
	def_pilha q;

    if (*pilha==NULL) return 0;

    q = (*pilha);
    q->str = strp;

    (*pilha) = (*pilha)->prox;
    free(q);

    return 1;
}

void visualiza(def_pilha pilha)
{
    while (pilha != NULL)
    {
          printf("%c", pilha->str);
          pilha=pilha->prox;
    }
    printf(" ");
}

int main()
{
    char strp[MAX], frase;
    int op, nP, i, d;
   def_pilha pilha1 = NULL, pilha2 = NULL;


            printf("Frase: ");
            gets(strp);

            printf("Frase: %s\n", strp);
            
            i = 0;
            d = strlen(strp);
            while (i < d)
            {
                if (strp[i] != ' ')
                {
                    empilha(&pilha1, strp[i]);
                } else if (strp[i] == ' ')
                {
                    visualiza(pilha1);
                    pilha1 = NULL;
                }
                i++;
            }
            visualiza(pilha1);
            printf("\n");


   return 1;
}
