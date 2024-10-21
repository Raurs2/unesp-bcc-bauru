/*
   Fila Din‰mica  - Lista Linear Simplesmente Encadeada
   						com Descritor
   Fila com elementos diferentes: int, char[20], float

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define IT 1
#define ST 2
#define FL 3

typedef union {
           	   int intinfo;
               char stringinfo[20];
               float floatinfo;
              } no_info;

typedef struct tipo_no {
		          int tipo;
                  no_info info;
                  struct tipo_no* prox;} No;

typedef struct {  No* inicio;
                  No* final;} def_fila;

typedef struct tipo_info {
		          int tipo;
                  no_info info;
                  } *Tipo_Info;


int vazia(def_fila Fila){
     return (Fila.inicio == NULL);
}

void enfileira(def_fila* Fila, Tipo_Info dado){	
     No* q = (No*)malloc(sizeof(No));
     q->tipo = dado->tipo;
     q->info = dado->info;
     q->prox = NULL;
     
     if (vazia(*Fila)) Fila->inicio = q;
     else Fila->final->prox = q;
     Fila->final=q;
}

int desenfileira(def_fila* Fila, Tipo_Info *dado){ 
     No* q;

    if (vazia(*Fila)) return 0;
    else{
         q = (*Fila).inicio;
         (*dado)->tipo = q->tipo;
         (*dado)->info = q->info;
         if ((*Fila).inicio == (*Fila).final)
         	(*Fila).final=NULL;
         (*Fila).inicio = q->prox;
         free(q);
         return 1;}
}

void imprime(def_fila Fila)
{ No* q;
    q = Fila.inicio;
    while (q != NULL){
    	switch (q->tipo){
          	case IT: printf("%d\t", q->info.intinfo);break;
          	case ST: printf("%s\t", q->info.stringinfo);break;
          	case FL: printf("%.2f\t", q->info.floatinfo);break;
            }
          q=q->prox;}
    printf("\n\n");
}

int main(void){   
    def_fila fila;
    Tipo_Info dado;
    int tipo;
    char op;

    fila.inicio = fila.final = NULL;
    printf("Insercao de valores na fila... \n");
    do{
  		 dado = (Tipo_Info)malloc(sizeof(struct tipo_info));
  		 do{
            printf("Inserir elementos (s/n)?..."); op=getche();
         }while (op!='s' && op!='S' && op!='n' && op!='N');
         if (op=='s' || op=='S'){
            printf("\nInserir (1)Int (2)String (3)Float ");tipo=getche()-48;
            dado->tipo=tipo;
            switch (tipo){
            	case IT: printf("\n\tInserir um numero inteiro ");
               		 	scanf("%d",&dado->info.intinfo);break;
            	case ST:	printf("\n\tInserir uma palavra ");
               		  	scanf("%s",&dado->info.stringinfo); fflush(stdin);break;
            	case FL:	printf("\n\tInserir um numero float ");
               		  	scanf("%f",&dado->info.floatinfo);break;}
            enfileira(&fila,dado); }
    }while (op=='s' || op=='S');
    if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");imprime(fila);}
    do{
        do{ printf("\nRetirar elementos (s/n)?...");op=getche();
        }while (op!='s' && op!='S' && op!='n' && op!='N');
        if (op=='s' || op=='S') {
           if (!desenfileira(&fila,&dado)) printf("Remocao sem sucesso\n");
           else{if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");imprime(fila);}}}
    }while (op=='s' || op=='S');
    if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");imprime(fila);}
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
