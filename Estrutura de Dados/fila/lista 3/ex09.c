/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no* prox;
} *def_fila;

int vazia(def_fila inicio)
{
    return (inicio == NULL);
}

def_fila cria_no(int numero)
{	
    def_fila q = (def_fila) malloc(sizeof(struct no));

    q->dado=numero;
    q->prox=NULL;

    return q;
}

void enfileira(def_fila* inicio, def_fila* final, int numero)
{ 
    def_fila q = cria_no(numero);

    if (*final != NULL) (*final)->prox=q;
    else *inicio=q;
    
    *final=q;
}

int desenfileira(def_fila* inicio, def_fila* final, int* numero)
{ 
    def_fila q;

    if (*inicio == NULL) return 0;

    q = *inicio;
    *inicio = (*inicio)->prox;

    if (*inicio == NULL) *final=NULL;

    *numero = q->dado;
    free(q);

    return 1;
}

void visualiza(def_fila inicio)
{ 
    def_fila q;

    q=inicio;
    while (q != NULL)
    {
        printf("%d ", q->dado);
        q=q->prox;
    }
    printf("\n\n");
}

int main()
{   
    def_fila filaI, filaF, auxI, auxF;
    int elemento;
    int op;

    filaI=filaF=NULL;
    auxI=auxF=NULL;

do
    {
        do
        {
            printf("\n1 - incluir\n2 - Remover\n3 - ver\n4 - Remover negativos\n5 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 5);

        if (op == 1)
        {
            printf("elemento: ");
            scanf("%d", &elemento);

            enfileira(&filaI, &filaF, elemento);

        } else if (op == 2)
        {
            if (desenfileira(&filaI, &filaF, &elemento))
            {
                printf("elemento %d Removido\n", elemento);
            } else printf("Acabou os elementos\n");
        } else if (op == 3)
        {
            printf("\n");
            visualiza(filaI);
            printf("\n");
        } else if (op == 4)
        {
            while (desenfileira(&filaI, &filaF, &elemento))
                if (elemento >= 0)
                    enfileira(&auxI, &auxF, elemento);

            while (desenfileira(&auxI, &auxF, &elemento))
                enfileira(&filaI, &filaF, elemento);

            printf("\nRemovido!\n");
        }
    } while (op != 5);

    
}

