#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct no_pilha{
			char mercadoria[30];
			char cor[30];
			int quant;
            struct no_pilha *prox;
			}*def_pilha;


int vazia(def_pilha pilha){
 	return(pilha==NULL);
}

void empilha(def_pilha* pilha, char mercadoria[], char cor[], int quant){
	def_pilha q =(def_pilha) malloc(sizeof(struct no_pilha));
    strcpy(q->mercadoria,mercadoria);
    strcpy(q->cor,cor);
    q->quant = quant;
    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, char mercadoria[],char cor[], int *quant){
	def_pilha q;

    if (vazia(*pilha)) return 0;
    q = (*pilha);
    strcpy(mercadoria,q->mercadoria);
    strcpy(cor,q->cor);
    *quant = q->quant;
    (*pilha) = (*pilha)->prox;
    free(q);
    return 1;
}

int arruma (def_pilha *P1, def_pilha *P2, char mercadoria[], char cor[], int *total){
 def_pilha P3=NULL;
 char mercadoria1[30], cor1[30];
 int qt;
    if (vazia(*P1)) return 0;
 	// Ordem: todas as mercadorias de um tipo e de uma certa cor
    if((strcmp(mercadoria,"todas")!=0)&&(strcmp(cor,"todas")!=0)){
    	while (desempilha(P1,&mercadoria1,&cor1,&qt)){
	 	   	if (strcmp(mercadoria,mercadoria1)==0 && strcmp(cor,cor1)==0){
				*total+=qt;
				empilha(P2,mercadoria,cor,qt);}
			else empilha (&P3,mercadoria1,cor1,qt);
		}
		while(desempilha(&P3,&mercadoria1,&cor1,&qt)) empilha(P1,mercadoria1,cor1,qt);
		return 1;
	}
	 
	// Ordem: todas as mercadorias de um tipo, independente da cor
	if(strcmp(mercadoria,"todas")!=0){
    	while (desempilha(P1,&mercadoria1,&cor1,&qt)){
	 	   	if (strcmp(mercadoria,mercadoria1)==0){
				*total+=qt;
				empilha(P2,mercadoria1,cor1,qt);}
			else empilha (&P3,mercadoria1,cor1,qt);
		}
		while(desempilha(&P3,&mercadoria1,&cor1,&qt)) empilha(P1,mercadoria1,cor1,qt);
		return 1;
	}
	
	// Ordem: todas as mercadorias de uma cor
	if(strcmp(cor,"todas")!=0){
    	while (desempilha(P1,&mercadoria1,&cor1,&qt)){
	 	   	if (strcmp(cor,cor1)==0){
				*total+=qt;
				empilha(P2,mercadoria1,cor1,qt);}
			else empilha (&P3,mercadoria1,cor1,qt);
		}
		while(desempilha(&P3,&mercadoria1,&cor1,&qt)) empilha(P1,mercadoria1,cor1,qt);
		return 1;
	}

}


void visualiza(def_pilha pilha){
    while (pilha!=NULL){
          printf("\nA mercadoria: %s  ", pilha -> mercadoria);
          printf("de cor: %s  ",pilha->cor);
          printf("tem:  %d na caixa.",pilha->quant);
          pilha=pilha->prox;};
    printf("\n");
}


int main (void){
   int numero=0,ok,quant, total;
   char mercadoria[10],cor[10];
   char opcao;
   def_pilha pilha,pilha2;

   pilha=NULL; pilha2=NULL;
   printf("\nInsercao de valores na pilha ... Digite ""sair"" para encerrar\n");
   do{
           printf("Empilhar mercadoria = ");
	       gets(mercadoria);
           if(strcmp(mercadoria,"sair")!=0 ){ 
		      printf("Mercadoria de cor = ");
	          gets(cor);
	          printf("Qt de Mercadoria na caixa = ");
	          scanf("%d",&quant); fflush(stdin);
              empilha(&pilha,mercadoria,cor,quant);}
           else numero = -1;
   }while (numero != -1);
   if (vazia(pilha)) printf("Pilha vazia\n");
   else { printf("\nPilha com elementos: "); visualiza(pilha);}
   printf("\nTermino do empilhamento\n----\n");

	printf("\n\nOrdem do gerente:");
	printf("\nMercadoria (ou todas)"); gets(mercadoria);
	printf("\nCor (ou todas)"); gets(cor);
	total=0;
    arruma(&pilha,&pilha2,mercadoria,cor,&total);

    if (vazia(pilha)) printf("Pilha inicial vazia\n");
    else { printf("\nPilha inicial com elementos: "); visualiza(pilha);}
    
	printf("\nQauntidade de mercadorias = %d",total);
    if (vazia(pilha2)) printf("Pilha solicitada vazia\n");
    else { printf("\nPilha solicitada com elementos: "); visualiza(pilha2);}

   printf("\n\nDigite algo para encerrar ...");getch();
   return 1;
}
