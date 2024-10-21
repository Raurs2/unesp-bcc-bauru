#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 3

//Raul Alexandre Gonzalez Augusto

typedef struct no_pilha
{
    char str;
    struct no_pilha *prox;
} *def_pilha;

def_pilha cria_no( char strp)
{	
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));
    strcpy(q->str, strp);
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* pilha, char strp[MAX])
{
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));

    strcpy(q->str, strp);

    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, char strp[MAX])
{
	def_pilha q;

    if (*pilha==NULL) return 0;

    q = (*pilha);
    strcpy(strp, q->str);

    (*pilha) = (*pilha)->prox;
    free(q);

    return 1;
}

void visualiza(def_pilha pilha)
{
    printf("\n");
    while (pilha != NULL)
    {
          printf("%s\n", pilha->str);
          pilha=pilha->prox;
    }
    printf("\n");
}

int main()
{
    char strp[MAX], frase[MAX];
    int op, nP;
   def_pilha pilha1 = NULL, pilha2 = NULL;

    do
    {
        do
        {
            printf("\n1 - Frase\n2 - inverter\n4 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 4);
        
        nP = 0;
        
        if (op == 1)
        {
            getchar();

            printf("Frase: ");
            scanf("%s", &strp);
        } else if (op == 2)
        {
            printf("Frase: %s\n", strp);
            
            visualiza(pilha1);
        } else if (op == 3)
        {
            
        }
        
           
        
    } while (op != 4);

   return 1;
}
