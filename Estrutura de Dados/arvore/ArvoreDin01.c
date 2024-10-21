/* 	Árvore Dinâmica
      Grau 3 - Inserção, Impressão e Busca
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define Grau 3

typedef struct no{
         char info;
         struct no* primeiro;
         struct no* segundo;
         struct no* terceiro;
         } *def_arvore;

void cria_filhos(def_arvore* arvore){
	 int i,qt;
     char filho;
     def_arvore p;

     printf("\nLeitura dos filhos de : %c\n", (*arvore)->info);
     do{ printf("Quantos filhos sao: ");scanf("%d",&qt);
     }while (qt>Grau);
     for(i=1;i<=qt;i++){
         printf("\nFilho = ");filho=getche();
         if(filho!='0'){
              p=(def_arvore)malloc(sizeof(struct no));
              p->info=filho;
              p->primeiro=NULL;
              p->segundo=NULL;
              p->terceiro=NULL;
              switch (i){
                   case 1: (*arvore)->primeiro=p;break;
                   case 2: (*arvore)->segundo=p;break;
                   case 3: (*arvore)->terceiro=p;break;
              }}}
}

void cria_arvore(def_arvore* arvore){
		char ok;

      printf("\n\nO no %c tem filhos?(S/N)",(*arvore)->info);
      ok=getche();
      if(ok=='S' || ok=='s'){
         cria_filhos(arvore);
         if((*arvore)->primeiro!=NULL)cria_arvore(&((*arvore)->primeiro));
         if((*arvore)->segundo!=NULL) cria_arvore(&((*arvore)->segundo));
         if((*arvore)->terceiro!=NULL)cria_arvore(&((*arvore)->terceiro));}
}


void le_arvore (def_arvore* arvore){	  
     char dado;

     printf("\nEntre com a raiz = ");dado=getche();
     (*arvore)=(def_arvore)malloc(sizeof(struct no));;
     (*arvore)->info=dado;
     (*arvore)->primeiro=NULL;
     (*arvore)->segundo=NULL;
     (*arvore)->terceiro=NULL;
     cria_arvore(arvore);
}

void mostra_arvore(def_arvore arvore, int *nivel){
    int i,nivel1;

      for(i=0;i<=(*nivel)*2;i++) printf("  ");
      printf("%c\n",arvore->info);
      nivel1=(*nivel)+1;
      if(arvore->primeiro!=NULL)
         mostra_arvore(arvore->primeiro,&nivel1);
      if(arvore->segundo!=NULL)
         mostra_arvore(arvore->segundo,&nivel1);
      if(arvore->terceiro!=NULL)
         mostra_arvore(arvore->terceiro,&nivel1);
}

int busca(def_arvore arvore, char valor){
 	if(arvore==NULL) return 0;
   return (arvore->info==valor || busca(arvore->primeiro,valor) ||busca(arvore->segundo,valor) ||busca(arvore->terceiro,valor));
}

int conta_nos_todos_filhos(def_arvore arvore){
  int i,cont=0;
    
  	if(arvore==NULL) return 0;
  	printf("\nEntrou.... \t pai=%d", arvore->info);
  	cont+=conta_nos_todos_filhos(arvore->primeiro); 
  	cont+=conta_nos_todos_filhos(arvore->segundo); 
  	cont+=conta_nos_todos_filhos(arvore->terceiro); 
    if (arvore->primeiro!= NULL && arvore->segundo !=NULL && arvore->terceiro!=NULL){
   		cont++; 
		   printf("\n3 filhos, cont=%d.... \t %d, %d, %d", cont, arvore->primeiro->info,arvore->segundo->info,arvore->terceiro->info);}
   return(cont);
}

int main(){
	def_arvore arvore=NULL;
	int nivel=0,y;

   le_arvore(&arvore);
   printf("\n\n\nMostrando a arvore....\n");
   mostra_arvore(arvore,&nivel);
   y=conta_nos_todos_filhos(arvore);printf("\n\nNos com todos os filhos=%d",y);
   printf("\n\n\aTecle algo para encerrar ...");getch();
}
