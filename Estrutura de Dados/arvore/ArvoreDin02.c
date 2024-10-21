/* 	Árvore Genérica
 
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define Grau 5

typedef struct no_arvore{
		 char info;
         struct no_arvore* filhos[Grau];
         } *def_arvore;


void cria_filhos(def_arvore* arvore)
{	  int i,j,qt;
	  int filho;
     def_arvore p;

	  printf("\nLeitura dos filhos de : %c\n", (*arvore)->info);
     do{
     		printf("Quantos filhos sao: ");scanf("%d",&qt);
     }while (qt>Grau);
     for(i=1;i<=qt;i++){
         printf("\nFilho = ");filho=getche();
         if(filho!='0'){
              p=(def_arvore)malloc(sizeof(struct no_arvore));
              p->info=filho;
              for(j=0;j<Grau;j++) p->filhos[j]=NULL;
              (*arvore)->filhos[i]=p;
              }}
}

void cria_arvore(def_arvore* arvore){
		char ok;
		int j;

      printf("\n\nO no %c tem filhos?(S/N)",(*arvore)->info);
      ok=getche();
      if(ok=='S' || ok=='s'){
         cria_filhos(arvore);
         for(j=0;j<Grau;j++)
         	if((*arvore)->filhos[j]!=NULL)
            	cria_arvore(&((*arvore)->filhos[j]));
			}
}


void le_arvore (def_arvore* arvore){
	  int dado,j;

     printf("\nEntre com a raiz = ");dado=getche();
     (*arvore)=(def_arvore)malloc(sizeof(struct no_arvore));;
     (*arvore)->info=dado;
      for(j=0;j<Grau;j++) (*arvore)->filhos[j]=NULL;
     cria_arvore(arvore);
}


void mostra_arvore(def_arvore arvore, int *nivel){
 int i,nivel1;

      for(i=0;i<=(*nivel)*2;i++) printf("  ");
      printf("%c\n",arvore->info);
      nivel1=(*nivel)+1;
      for(i=0;i<Grau;i++){
        	if(arvore->filhos[i]!=NULL)
           	mostra_arvore(arvore->filhos[i],&nivel1);}
}


int main(){
  def_arvore arvore;
	int nivel;

   le_arvore(&arvore);
   printf("\n\n\nMostrando a arvore....\n");
   nivel=0;mostra_arvore(arvore,&nivel);
   printf("\n\n\aTecle algo para encerrar ...");getch();
}
