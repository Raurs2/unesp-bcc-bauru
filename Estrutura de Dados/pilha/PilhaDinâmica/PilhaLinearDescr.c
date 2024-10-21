#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct no_pilha{
	    int  dado;
      	struct no_pilha *prox;
        } No;
typedef struct descritor{
	    int quantidade;
      	No *pilha;
        } def_pilha;


int vazia(def_pilha Pilha){
 	return(Pilha.pilha==NULL);
}

No* cria_no(int numero){	
    No* q = (No*) malloc(sizeof(struct no_pilha));
    q->dado=numero;
    q->prox=NULL; 
    return q;
}

void empilha(def_pilha* Pilha, int numero){
	No* q = cria_no(numero);
    if(!vazia(*Pilha)) q->prox = Pilha->pilha;
    Pilha->pilha = q;
    Pilha->quantidade++;
}

int desempilha(def_pilha* Pilha, int* numero){
	No* q;
    if(vazia(*Pilha)) return 0;
    q = Pilha->pilha;
    *numero = q->dado;
    Pilha->pilha = Pilha->pilha->prox;
    free(q);
    Pilha->quantidade--;
    return 1;
}

void visualiza(def_pilha Pilha){
   
   while (Pilha.pilha!=NULL){
          printf("\t%d", Pilha.pilha->dado);
          Pilha.pilha=Pilha.pilha->prox;};
    printf("\n");
}
 

int main (void){
   int numero,ok;
   char opcao;
   def_pilha Pilha;

   Pilha.pilha=NULL;
   Pilha.quantidade = 0;
   printf("\nInsercao de valores na pilha ... Digite -1 para encerrar\n");
   do{
           printf("Empilhar numero = ");
	       scanf("%d",&numero);
           if (numero != -1) empilha(&Pilha,numero);
   }while (numero != -1);
   if (vazia(Pilha)) printf("Pilha vazia\n");
   else { printf("\nPilha com %d elementos: ",Pilha.quantidade); visualiza(Pilha);}
   printf("\nTermino do empilhamento\n----\n");

   ok=1;
   do{
           printf("Desempilhar elemento?(S/N)  ");
           opcao=getche();
           if (opcao == 's' || opcao == 'S'){
              if (desempilha(&Pilha,&numero)) printf("\tRemoveu %d... \n",numero);
              else ok=0;}
           else ok=0;
   }while (ok!=0);
   if (vazia(Pilha)) printf("Pilha vazia\n");
   else {printf("\nPilha com %d elementos: ",Pilha.quantidade);visualiza(Pilha);}
   printf("\nTermino do Desempilhamento\n----\n");


   printf("\n\nDigite algo para encerrar ...");getch();
   return 1;
}
