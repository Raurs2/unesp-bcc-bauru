/*
   Apostila Pilha
   Exercício 01 - Pilha estática
					   pilha[0] = topo
					   pilha[1] a pilha[max-1] = elementos
*/

#include <stdio.h>
#include <conio.h>

#define max 10

typedef int def_pilha[max];


int vazia (def_pilha Pilha){
     	return (Pilha[0] == 0);
}

int cheia (def_pilha Pilha){
     	return (Pilha[0] == (max-1));

}

int empilha (def_pilha Pilha, int x){
     	if (cheia(Pilha)) return 0;
        Pilha[++(Pilha[0])]=x;
        return 1;
}

int desempilha (def_pilha Pilha, int* x){
     	if (vazia(Pilha)) return 0;
        *x = Pilha[(Pilha[0])--];
        return 1;
}

void visualiza_pilha (def_pilha Pilha){
	int i=Pilha[0];
	if (i >= 0){
     for(; i>0; i--)printf("\t%d",Pilha[i]);}
   else printf(" esta vazia");
}

void mostra_pilha (def_pilha Pilha){
	def_pilha Aux; int X;
	Aux[0]=0;
	while(desempilha(Pilha,&X)){
		printf("\t%d",X);
		empilha(Aux,X);
	}
	while(desempilha(Aux,&X))
		empilha(Pilha,X);
}

int main (void){
    def_pilha Pilha;
 	  int elemento, ok;
	  char opcao;

     Pilha[0]=0;
     do{
           printf("Empilhar elemento = ");
			  scanf("%d",&elemento);
           if (elemento != -1)
              if (!empilha(Pilha,elemento)) printf(" Não empilhou\n");
     }while (elemento != -1);

     if (vazia(Pilha)) printf("Pilha vazia");
     else { printf("\nPilha com elementos: "); visualiza_pilha(Pilha);}
     printf("\nTermino do empilhamento\n----\n");
     
     ok=1;
     do{
           printf("\nDesempilhar elemento?(S/N) ");
           opcao=getche();
           if (opcao == 's' || opcao == 'S'){
              if (desempilha(Pilha,&elemento)) printf("\nDesempilhou: %d\n",elemento);
              else ok=0;}
           else ok=0;
     }while (ok!=0);
     
     if (vazia(Pilha)) printf("Pilha vazia\n");
     else {printf("\nPilha com elementos:  ");visualiza_pilha(Pilha);}
     printf("\n\nTermino do Desempilhamento\n----\n");
     
      if (vazia(Pilha)) printf("Pilha vazia\n");
     else {printf("\nMostarndo a Pilha:  ");mostra_pilha(Pilha);}
     
     printf("\n\n\aDigite algo para encerrar ... ");getch();
     return 1;
}

