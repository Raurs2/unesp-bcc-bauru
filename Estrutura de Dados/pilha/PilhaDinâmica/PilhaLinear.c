#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct no_pilha{
			int dado;
            struct no_pilha *prox;
			}*def_pilha;


int vazia(def_pilha pilha){
 	return(pilha==NULL);
}

def_pilha cria_no(int numero){	
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));
    q->dado=numero;
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* pilha, int numero){
	def_pilha q =(def_pilha) malloc(sizeof(struct no_pilha));
    q->dado = numero;
    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, int* numero){
	def_pilha q;

    if (vazia(*pilha)) return 0;
    q = (*pilha);
    *numero = q->dado;
    (*pilha) = (*pilha)->prox;
    free(q);
    return 1;
}

void visualiza(def_pilha pilha){
    while (pilha!=NULL){
          printf("\t%d", pilha -> dado);
          pilha=pilha->prox;};
    printf("\n");
}


int main (void){
   int numero,ok;
   char opcao;
   def_pilha pilha;

   pilha=NULL;
   printf("\nInsercao de valores na pilha ... Digite -1 para encerrar\n");
   do{
           printf("Empilhar numero = ");
	       scanf("%d",&numero);
           if (numero != -1) empilha(&pilha,numero);
   }while (numero != -1);
   if (vazia(pilha)) printf("Pilha vazia\n");
   else { printf("\nPilha com elementos: "); visualiza(pilha);}
   printf("\nTermino do empilhamento\n----\n");

   ok=1;
   do{
           printf("Desempilhar elemento?(S/N)  ");
           opcao=getche();
           if (opcao == 's' || opcao == 'S'){
              if (desempilha(&pilha,&numero)) printf("\tRemoveu %d... \n",numero);
              else ok=0;}
           else ok=0;
   }while (ok!=0);
   if (vazia(pilha)) printf("Pilha vazia\n");
   else {printf("\nPilha com elementos:  ");visualiza(pilha);}
   printf("\nTermino do Desempilhamento\n----\n");


   printf("\n\nDigite algo para encerrar ...");getch();
   return 1;
}
