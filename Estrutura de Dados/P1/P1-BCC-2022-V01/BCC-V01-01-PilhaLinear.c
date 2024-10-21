#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct no_pilha{
			char mercadoria[10];
			char cor[10];
            struct no_pilha *prox;
			}*def_pilha;


int vazia(def_pilha pilha){
 	return(pilha==NULL);
}

void empilha(def_pilha* pilha, char mercadoria[], char cor[]){
	def_pilha q =(def_pilha) malloc(sizeof(struct no_pilha));
    strcpy(q->mercadoria,mercadoria);
    strcpy(q->cor,cor);
    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, char mercadoria[],char cor[]){
	def_pilha q;

    if (vazia(*pilha)) return 0;
    q = (*pilha);
    strcpy(mercadoria,q->mercadoria);
    strcpy(cor,q->cor);
    (*pilha) = (*pilha)->prox;
    free(q);
    return 1;
}

int arruma (def_pilha *P1, def_pilha *P2, char mercadoria[], char cor[]){
 def_pilha P3=NULL;
 char mercadoria1[10], cor1[10];
 
    if (vazia(*P1)) return 0;
 	// Ordem: todas as mercadorias de um tipo e de uma certa cor
    if((strcmp(mercadoria,"todas")!=0)&&(strcmp(cor,"todas")!=0)){
    	while (desempilha(P1,&mercadoria1,&cor1)){
	 	   	if (strcmp(mercadoria,mercadoria1)==0 && strcmp(cor,cor1)==0){
				empilha(P2,mercadoria,cor);}
			else empilha (&P3,mercadoria1,cor1);
		}
		while(desempilha(&P3,&mercadoria1,&cor1)) empilha(P1,mercadoria1,cor1);
		return 1;
	}
	 
	// Ordem: todas as mercadorias de um tipo, independente da cor
	if(strcmp(mercadoria,"todas")!=0){
    	while (desempilha(P1,&mercadoria1,&cor1)){
	 	   	if (strcmp(mercadoria,mercadoria1)==0)
				empilha(P2,mercadoria1,cor1);
			else empilha (&P3,mercadoria1,cor1);
		}
		while(desempilha(&P3,&mercadoria1,&cor1)) empilha(P1,mercadoria1,cor1);
		return 1;
	}
	
	// Ordem: todas as mercadorias de uma cor
	if(strcmp(cor,"todas")!=0){
    	while (desempilha(P1,&mercadoria1,&cor1)){
	 	   	if (strcmp(cor,cor1)==0)
				empilha(P2,mercadoria1,cor1);
			else empilha (&P3,mercadoria1,cor1);
		}
		while(desempilha(&P3,&mercadoria1,&cor1)) empilha(P1,mercadoria1,cor1);
		return 1;
	}
}

void visualiza(def_pilha pilha){
    while (pilha!=NULL){
          printf("\n%s", pilha -> mercadoria);
          printf("\t%s",pilha->cor);
          pilha=pilha->prox;};
    printf("\n");
}


int main (void){
   int numero=0,ok;
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
              empilha(&pilha,mercadoria,cor);}
           else numero = -1;
   }while (numero != -1);
   if (vazia(pilha)) printf("Pilha vazia\n");
   else { printf("\nPilha com elementos: "); visualiza(pilha);}
   printf("\nTermino do empilhamento\n----\n");

	printf("\n\nOrdem do gerente:");
	printf("\nMercadoria (ou todas)"); gets(mercadoria);
	printf("\nCor (ou todas)"); gets(cor);
	
    arruma(&pilha,&pilha2,mercadoria,cor);

     if (vazia(pilha)) printf("Pilha vazia\n");
   else { printf("\nPilha com elementos: "); visualiza(pilha);}
     if (vazia(pilha2)) printf("Pilha Solicitada vazia\n");
   else { printf("\nPilha Solicitada com elementos: "); visualiza(pilha2);}

   printf("\n\nDigite algo para encerrar ...");getch();
   return 1;
}
