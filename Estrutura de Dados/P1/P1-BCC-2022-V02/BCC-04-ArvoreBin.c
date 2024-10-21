/* 	Árvore Binária
      Inserção, Impressão e Busca

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct no_arvore{
			   int info;
         struct no_arvore* esq;
         struct no_arvore* dir;
         } *def_arvore;

void mostra_arvore(def_arvore arvore, int *nivel){
 int i,nivel1;

      for(i=0;i<=(*nivel)*2;i++) printf("  ");
      printf("%d\n",arvore->info);
      nivel1=(*nivel)+1;
      if(arvore->dir!=NULL)
         mostra_arvore(arvore->dir,&nivel1);
      if(arvore->esq!=NULL)
         mostra_arvore(arvore->esq,&nivel1);
}

void cria_arvore(def_arvore* arvore){
		char ok;
		int filho;
      def_arvore p;

      printf("\n\nO no %d tem filhos?(S/N)",(*arvore)->info);
      ok = getche();
      if(ok=='S' || ok=='s'){
	  		printf("\nLeitura dos filhos de : %d\n", (*arvore)->info);
     		printf("Entre com o filho da esquerda (-1 para nulo): ");
     		scanf("%d",&filho);
     		if(filho!=-1){
              p=(def_arvore)malloc(sizeof(struct no_arvore));
              p->info=filho;
              p->esq=NULL;
              p->dir=NULL;
              (*arvore)->esq=p;}
     		printf("Entre com o filho da direita (-1 para nulo): ");
     		scanf("%d",&filho);
     		if(filho!=-1){
              p=(def_arvore)malloc(sizeof(struct no_arvore));
              p->info=filho;
              p->esq=NULL;
              p->dir=NULL;
              (*arvore)->dir=p;}
         if((*arvore)->esq!=NULL)cria_arvore(&((*arvore)->esq));
         if((*arvore)->dir!=NULL) cria_arvore(&((*arvore)->dir));}
}


void le_arvore (def_arvore* arvore){
	  int dado;

     printf("\nEntre com a raiz = ");scanf("%d",&dado);
     (*arvore)=(def_arvore)malloc(sizeof(struct no_arvore));;
     (*arvore)->info=dado;
     (*arvore)->esq=NULL;
     (*arvore)->dir=NULL;
     cria_arvore(arvore);
}

int conta_ao_menos_1_filho (def_arvore arvore){
  int i,cont=0,cont1;
    
  	if(arvore==NULL) return 0;
    if(!((arvore->esq==NULL) && (arvore->dir==NULL)))cont+=arvore->info;
	cont+=conta_ao_menos_1_filho(arvore->esq)+conta_ao_menos_1_filho(arvore->dir);
   return(cont);
}


void pre_ordem(def_arvore arvore){
	if (arvore==NULL) return;
	printf("%d\t",arvore->info);
	pre_ordem(arvore->esq);
	pre_ordem(arvore->dir);
}
void em_ordem(def_arvore arvore){
	if (arvore==NULL) return;
    em_ordem(arvore->esq);
	printf("%d\t",arvore->info);
	em_ordem(arvore->dir);
}
void pos_ordem(def_arvore arvore){
	if (arvore==NULL) return;
	pos_ordem(arvore->esq);
	pos_ordem(arvore->dir);
	printf("%d\t",arvore->info);
}

int main(){
	  def_arvore arvore;
	  int numero, nivel=0;

     printf("Leitura da Arvore\n");
     le_arvore(&arvore);
     printf("\n\aA arvore binaria formada e: \n");
     mostra_arvore(arvore,&nivel);
     printf("conta_ao_menos_1_filho = %d",conta_ao_menos_1_filho(arvore));
    
     printf("\n\nImprimindo em PRE-ORDEM\n");pre_ordem(arvore);
     printf("\n\nImprimindo em EM-ORDEM\n");em_ordem(arvore);
	 printf("\n\nImprimindo em POS-ORDEM\n");pos_ordem(arvore);    
     printf("\n\n\aTecle algo para encerrar ...");getch();
}
