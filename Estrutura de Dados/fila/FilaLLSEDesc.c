/*
   Fila Din‰mica  - Lista Linear Simplesmente Encadeada
   						com Descritor

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>


typedef struct no {
		int dado;
        struct no* prox;} No;

typedef struct Descritor {
		No* inicio;
        No* final;} def_fila;


int vazia(def_fila Fila){
     return (Fila.inicio == NULL);
}

No* cria_no(int numero){	
    No* q = (No*) malloc(sizeof(struct no));
    q->dado=numero;
    q->prox=NULL;
    return q;
}

void enfileira(def_fila* Fila, int numero){
     No* q = cria_no(numero);
     if (vazia(*Fila)) Fila->inicio = q;
     else Fila->final->prox = q;
     Fila->final=q;
}

int desenfileira(def_fila* Fila, int* numero){ 
    No* q;

    if (vazia(*Fila)) return 0;
    q = (*Fila).inicio;
    *numero = q->dado;
    if ((*Fila).inicio == (*Fila).final)
       	(*Fila).final=NULL;
    (*Fila).inicio = q->prox;
    free(q);
    return 1;
}

void visualiza(def_fila Fila){ 
    No* q;

    q = Fila.inicio;
    while (q != NULL){
          printf("%d\t", q->dado);
          q=q->prox;}
    printf("\n\n");
}


int main(void){   
    def_fila fila;
    int numero;
    char op;

    fila.inicio = fila.final = NULL;
    printf("Insercao de valores na fila... \n");
    do{
         printf("Inserir elementos (s/n)?...");op=getche();
         if (op=='s' || op=='S'){
            printf("\tInserir qual = ");scanf("%d",&numero);
            enfileira(&fila,numero); }
    }while (op=='s' || op=='S');
    if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");visualiza(fila);}
    do{
        printf("\nRetirar elementos (s/n)?...");op=getche();
        if (op=='s' || op=='S') {
           if (!desenfileira(&fila,&numero)) printf("\tRemocao sem sucesso\n");
           else{printf("\tRemoveu: %d",numero);
		        if(!vazia(fila)){printf("\n\n\nImprimindo a fila...\n");visualiza(fila);}
                else printf("\nFila vazia");}}

    }while (op=='s' || op=='S');
    if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");visualiza(fila);}
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
