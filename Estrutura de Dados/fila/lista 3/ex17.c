/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no
{
    float dado;
    struct no* prox;
} *def_fila;

int vazia(def_fila inicio)
{
    return (inicio == NULL);
}

def_fila cria_no(float numero)
{	
    def_fila q = (def_fila) malloc(sizeof(struct no));

    q->dado=numero;
    q->prox=NULL;

    return q;
}

void enfileira(def_fila* inicio, def_fila* final, float numero)
{ 
    def_fila q = cria_no(numero);

    if (*final != NULL) (*final)->prox=q;
    else *inicio=q;
    
    *final=q;
}

int desenfileira(def_fila* inicio, def_fila* final, float* numero)
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
        printf("%.2f ", q->dado);
        q=q->prox;
    }
    printf("\n");
}

int main()
{   
    def_fila filaI, filaF, auxI, auxF, xI, xF;
    float elemento;
    int op, is1, is2;

    filaI=filaF=NULL;
    auxI=auxF=NULL;
    xI=xF=NULL;

    do
    {
        do
        {
            printf("\n1 - incluir\n2 - Remover\n3 - ver\n4 - Tranferir para fila 3\n5 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 5);

        if (op == 1)
        {
            printf("elemento: ");
            scanf("%f", &elemento);

            do
            {
                printf("\n1 = fila 1\n2 = fila 2\n3 = fila 3\n");
                scanf("%d", &op);
            } while (op < 1 && op > 3);

            if (op == 1)
                enfileira(&filaI, &filaF, elemento);
            else if (op == 2)
                enfileira(&auxI, &auxF, elemento);
            else if (op == 3)
                enfileira(&xI, &xF, elemento);
        } else if (op == 2)
        {
            do
            {
                printf("\n1 = fila 1\n2 = fila 2\n3 = fila 3\n");
                scanf("%d", &op);
            } while (op < 1 && op > 3);

            if (op == 1)
                if (desenfileira(&filaI, &filaF, &elemento))
                {
                    printf("elemento %.2f Removido\n", elemento);
                } else printf("Acabou os elementos\n");
            else if (op == 2)
                if (desenfileira(&auxI, &auxF, &elemento))
                {
                    printf("elemento %.2f Removido\n", elemento);
                } else printf("Acabou os elementos\n");
            else if (op == 3)
            {
                if (desenfileira(&xI, &xF, &elemento))
                {
                    printf("elemento %.2f Removido\n", elemento);
                } else printf("Acabou os elementos\n");
            }  
        } else if (op == 3)
        {
            printf("\n");
            visualiza(filaI);
            printf("\n");
            visualiza(auxI);
            printf("\n");
            visualiza(xI);
            printf("\n");
        } else if (op == 4)
        {
            is1 = is2 = 0;
            do
            {
                if (desenfileira(&filaI, &filaF, &elemento))
                {
                    enfileira(&xI, &xF, elemento);
                    is1 = 1;
                } else is1 = 0;
                if (desenfileira(&auxI, &auxF, &elemento))
                {
                    enfileira(&xI, &xF, elemento);
                    is2 = 1;
                } else is2 = 0;
            } while ( is1 || is2);
            printf("\nSucesso\n");
        }
    } while (op != 5);

    
}

