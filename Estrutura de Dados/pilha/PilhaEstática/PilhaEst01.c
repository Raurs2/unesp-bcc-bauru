/*
		Pilha estatica usando um vetor e topo separados

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100


typedef int def_pilha[MAX];

void inicializa (def_pilha* pilha, int* topo){	
     int i;
 	 *topo=-1;  // por ser um indice inválido para o vetor
 	 for (i=0;i<MAX;i++) (*pilha)[i]=0;   // não é necessário...
}

int vazia (int topo){
     	return (topo == -1);
}

int cheia (int topo){
     	return (topo == (MAX-1));
}

int empilha (def_pilha pilha, int *topo, int Elemento){
    // retorna se foi possível (1) ou não empilhar o ELEMENTO e atualiza o valor de TOPO
      if (cheia(*topo))return 0;
      pilha[++(*topo)]=Elemento;
      return 1;
}

int desempilha (def_pilha pilha, int *topo, int *Elemento){
    // retorna se foi possível (1) ou não desempilhar o ELEMENTO e atualiza o valor de TOPO
      if (vazia(*topo))return 0;
  	  *Elemento = pilha[(*topo)--];
      return 1;
}

void visualiza (def_pilha pilha, int topo){	
    // mostra como a pilha está. Usado para verificação
    int i=topo;
	if (topo >= 0)
     for(; i>=0; i--)printf("\t%d",pilha[i]);
   else printf(" esta vazia");
}



int main (void){    
     def_pilha pilha;
     int topo=-1,elemento,ok;
     char opcao;

     printf("A pilha ...... ");
     visualiza(pilha,topo);printf("\n");
     do{
	       printf("Empilhar elemento (-1 para sair)= ");
	       scanf("%d",&elemento);
	       if (elemento != -1)
	           if (!empilha(pilha,&topo,elemento)) printf(" Não empilhou\n");
     }while (elemento != -1);
     printf("\nTermino do empilhamento\n----\n");
     if (vazia(topo)) printf("Pilha vazia");
     else { printf("\nPilha com elementos: "); visualiza(pilha,topo);}
     ok=1;
     do{
	        printf("\nDesempilhar elemento?(S/N) ");
	        opcao=getche();
	        if (opcao == 's' || opcao == 'S'){
	           if (desempilha(pilha,&topo,&elemento)) printf("\nDesempilhou: %d\n",elemento);
	           else ok=0;}
	        else ok=0;
     }while (ok);
     if (vazia(topo)) printf("Pilha vazia\n");
     else {printf("\nPilha com elementos:  ");visualiza(pilha,topo);}
     printf("\n\nTermino do Desempilhamento\n----\n");

     printf("\n\n\aDigite algo para encerrar ... ");getch();
     return 1;
}

