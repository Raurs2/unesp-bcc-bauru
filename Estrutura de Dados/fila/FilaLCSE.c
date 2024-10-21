/*
   Fila Din‰mica  - Lista Circular

   inicio = final->prox

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>


typedef struct no {
		  int dado;
                  struct no* prox;
                  } *def_fila;

int vazia(def_fila Final){
     return (Final == NULL);
}

def_fila cria_no(int numero){	
    def_fila q = (def_fila) malloc(sizeof(struct no));
    q->dado=numero;
    q->prox=NULL;
    return q;
}

void enfileira(def_fila* Final, int numero){ 
     def_fila q = cria_no(numero);
     if (vazia(*Final)) (*Final)=q;
     else q->prox = (*Final)->prox;
     (*Final)->prox = q;
     *Final=q;
}

int desenfileira(def_fila* Final, int* numero){ 
    def_fila q;

    if (vazia(*Final)) return 0;
    q = (*Final)->prox;
    *numero = q->dado;
    if (q == *Final) *Final=NULL;
    else (*Final)->prox = q->prox;
    free(q);
    return 1;
}

void visualiza(def_fila Final){ 
    def_fila q;

    q = Final->prox;
    do{
			printf("%d\t", q->dado);
         q=q->prox;
    }while (q != Final->prox);
    printf("\n\n");
}


void main(void){  
    def_fila final;
	int numero;
    char op;

    final=NULL;
    printf("Insercao de valores na fila... \n");
    do{
         printf("Inserir elementos (s/n)?...");op=getche();
         if (op=='s' || op=='S'){
            printf("\tInserir qual = ");scanf("%d",&numero);
            enfileira(&final,numero); }
    }while (op=='s' || op=='S');
    if(!vazia(final)){ printf("\n\n\nImprimindo a fila...\n");visualiza(final);}
    do{
        printf("\nRetirar elementos (s/n)?...");op=getche();
        if (op=='s' || op=='S') {
           if (!desenfileira(&final,&numero)) printf("\tRemocao sem sucesso\n");
           else{printf("\tRemoveu: %d",numero);
		        if(!vazia(final)){printf("\n\n\nImprimindo a fila...\n");visualiza(final);}
                else printf("\nFila vazia");}}
    }while (op=='s' || op=='S');
    if(!vazia(final)){ printf("\n\n\nImprimindo a fila...\n");visualiza(final);}
    else printf("\nFila vazia");
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
