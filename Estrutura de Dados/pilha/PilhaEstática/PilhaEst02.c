#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct {
			int topo;
			int elementos[MAX];
            }def_pilha;
            
typedef struct no_pilha{
int info;
struct no_pilha *prox;
} *def_pilha;

int vazia (def_pilha pilha){
    if (pilha.topo == -1) return 1;
    return 0;
}

int cheia (def_pilha pilha){
    return (pilha.topo == (MAX-1));
}

int empilha (def_pilha *pilha, int Elemento){
    // retorna se foi poss�vel (1) ou n�o empilhar o ELEMENTO e atualiza o valor de PILHA->TOPO  
    if (cheia(*pilha)) return 0;
    pilha->elementos[++(pilha->topo)]=Elemento;
    return 1;
}

int desempilha (def_pilha *pilha,int *Elemento){
    // retorna se foi poss�vel (1) ou n�o desempilhar o ELEMENTO e atualiza o valor de PILHA->TOPO 
    if (vazia(*pilha))return 0;
    *Elemento = pilha->elementos[pilha->topo--];
    return 1;
}

void visualiza(def_pilha pilha){
 // mostra como a pilha est�. Usado para verifica��o
 	int i;
	if (!vazia(pilha))
       for(i=pilha.topo; i>=0; i--)  printf("\t%d",pilha.elementos[i]);
    else printf(" esta vazia");
    printf("\n");
}


int main (void)
{
	  int elemento, ok;
	  char opcao;
	  def_pilha pilha;

     pilha.topo=-1;
     printf("\n A pilha ......");visualiza(pilha);
     do{
           printf("Empilhar elemento (-1 para encerrar)= ");
           scanf("%d",&elemento);
           if (elemento != -1)
              if (!empilha(&pilha,elemento)) printf(" N�o empilhou\n");
     }while (elemento != -1);
     printf("\nTermino do empilhamento\n----\n");
     if (vazia(pilha)) printf("Pilha vazia\n");
     else { printf("\nPilha com elementos: "); visualiza(pilha);}
     ok=1;
     do{
           printf("Desempilhar elemento?(S/N) ");
           opcao=getche();
           if (opcao == 's' || opcao == 'S'){
              if (desempilha(&pilha,&elemento)) printf("\nDesempilhou: %d\n",elemento);
              else ok=0;}
           else ok=0;
     }while (ok!=0);
     if (vazia(pilha)) printf("Pilha vazia\n");
     else {printf("\nPilha com elementos:  ");visualiza(pilha);}
     printf("\nTermino do Desempilhamento\n----\n");
	  printf("\n\nDigite algo para encerrar ...");getch();
     return 1;
}
