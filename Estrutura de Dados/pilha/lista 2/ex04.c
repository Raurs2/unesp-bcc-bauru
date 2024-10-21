#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 3

//Raul Alexandre Gonzalez Augusto

typedef struct no_pilha
{
    char vagao[MAX];
    struct no_pilha *prox;
} *def_pilha;

def_pilha cria_no( char vagaop[])
{	
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));
    strcpy(q->vagao, vagaop);
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* pilha, char vagaop[MAX])
{
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));

    strcpy(q->vagao, vagaop);

    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, char vagaop[MAX])
{
	def_pilha q;

    if (*pilha==NULL) return 0;

    q = (*pilha);
    strcpy(vagaop, q->vagao);

    (*pilha) = (*pilha)->prox;
    free(q);

    return 1;
}

void visualiza(def_pilha pilha)
{
    printf("\n");
    while (pilha != NULL)
    {
          printf("%s\n", pilha->vagao);
          pilha=pilha->prox;
    }
    printf("\n");
}

int main()
{
    char vagaop[MAX];
    int op, nP;
   def_pilha pilhaP = NULL, pilhaR = NULL, pilhaC = NULL, pilhaCentral = NULL;

    do
    {
        do
        {
            printf("\n1 - incluir\n2 - Remover vagao\n3 - preparar locomotiva\n4 - ver vagoes\n5 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 5);
        
        nP = 0;
        
        if (op == 1)
        {
            getchar();

            printf("Vagao: ");
            scanf("%s", &vagaop);

            empilha(&pilhaCentral, vagaop);

        } else if (op == 2)
        {

            if (desempilha(&pilhaCentral, vagaop))
            {
                printf("Vagao %s Removido\n", vagaop);
            } else printf("Acabou os vagoes");
        } else if (op == 3)
        {
            while (desempilha(&pilhaCentral, vagaop))
            {
                if (!strcmp("VP", vagaop))
                {
                    empilha(&pilhaP, vagaop);
                    nP++;
                } else if (!strcmp("VR", vagaop))
                    empilha(&pilhaR, vagaop);
                else if (!strcmp("VC", vagaop))
                    empilha(&pilhaC, vagaop);
            }

            while (desempilha(&pilhaC, vagaop))
                empilha(&pilhaCentral, vagaop);

            while (nP > 1)
            {
                desempilha(&pilhaP, vagaop);
                empilha(&pilhaCentral, vagaop);
                nP--;
            }

            while (desempilha(&pilhaR, vagaop))
                empilha(&pilhaCentral, vagaop);
            
            desempilha(&pilhaP, vagaop);
            empilha(&pilhaCentral, vagaop);
        } else if (op == 4)
            visualiza(pilhaCentral);
        
    } while (op != 5);

   return 1;
}
