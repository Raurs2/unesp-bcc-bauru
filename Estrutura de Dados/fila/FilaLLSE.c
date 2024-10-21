/*
   Fila Din‰mica  - Lista Linear Simplesmente Encadeada
   insere no final
   remove do inicio

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>


typedef struct no {
		  int dado;
                  struct no* prox;
                  }* def_fila;

int vazia(def_fila Inicio){
     return (Inicio == NULL);
}

def_fila cria_no(int numero){	
    def_fila q = (def_fila) malloc(sizeof(struct no));
    q->dado=numero;
    q->prox=NULL;
    return q;
}

void enfileira(def_fila* Inicio, def_fila* Final, int numero){ 
     def_fila q = cria_no(numero);
     if (*Final != NULL) (*Final)->prox=q;
     else *Inicio=q;
     *Final=q;
}

int desenfileira(def_fila* Inicio,def_fila* Final, int* numero){ 
    def_fila q;

    if (*Inicio == NULL) return 0;
    q = *Inicio;
    *Inicio = (*Inicio)->prox;
    if (*Inicio == NULL) *Final=NULL;
    *numero = q->dado;
    free(q);
    return 1;
}

void visualiza(def_fila Inicio){ 
    def_fila q;

    q=Inicio;
    while (q != NULL){
          printf("%d\t", q->dado);
          q=q->prox;}
    printf("\n\n");
}


int main(void){   
    def_fila inicio, final;
    int numero;
    char op;

    inicio=final=NULL;
    printf("Insercao de valores na fila... \n");
    do{
         printf("Inserir elementos (s/n)?...");op=getche();
         if (op=='s' || op=='S'){
            printf("\tInserir qual = ");scanf("%d",&numero);
            enfileira(&inicio,&final,numero); }
    }while (op=='s' || op=='S');
    if(!vazia(inicio)){printf("\n\n\nImprimindo a fila...\n");visualiza(inicio);}
    else printf("\nFila vazia");
    do{
        printf("\nRetirar elementos (s/n)?...");op=getche();
        if (op=='s' || op=='S') {
           if (!desenfileira(&inicio,&final,&numero)) printf("\tRemocao sem sucesso\n");
           else{printf("\tRemoveu: %d",numero);
		        if(!vazia(inicio)){printf("\n\n\nImprimindo a fila...\n");visualiza(inicio);}
                else printf("\nFila vazia");}}
    }while (op=='s' || op=='S');
    if(!vazia(inicio)){printf("\n\n\nImprimindo a fila...\n");visualiza(inicio);}
    else printf("\nFila vazia");
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
