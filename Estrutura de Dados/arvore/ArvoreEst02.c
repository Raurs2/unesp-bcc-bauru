/* 	Árvore Estática
		representação do tipo 02

*/

#include <stdio.h>
#include <conio.h>

#define Max 30
#define Grau 3

typedef struct{
               char info;
               int nro_filhos;
               }elemento;
typedef elemento def_arvore[Max];


void inicializa_arvore(def_arvore arvore){
	int i;
    for(i=0;i<Max;i++){
       arvore[i].info='-';
       arvore[i].nro_filhos=0;}
}

void le_arvore(def_arvore arvore){
   int posicao=1,i,pai=0,qt;
   char filho, tem_filhos;

   printf("Raiz: ");arvore[pai].info=getche();
   while(arvore[pai].info!='-'){
       	  printf("\n\nO no %c tem filhos(s/n)?",arvore[pai].info);
       	  tem_filhos=getche();
       	  if(tem_filhos =='s' || tem_filhos =='S'){
          	  printf("\nLeitura dos filhos de: %c", arvore[pai].info);
				  printf("\nQuantos filhos: ");qt=getche()-48;
        		  arvore[pai].nro_filhos = qt;
   	    	  for(i=0; i<qt; i++){
      	     		printf("\nFilho = ");filho=getche();
              		if (filho!='0')arvore[posicao].info=filho;
              		posicao++;}
              }
       	  else arvore[pai].nro_filhos=0;
       pai++;}
}

void escreve_arvore(def_arvore arvore){
	int posicao=1,i,pai=0,cont,qt;

   if(arvore[0].info== '-'){
     printf("\n\n\aArvore vazia...");return;}

	printf("\n\n\aImpressao da arvore: \n");
   printf("Raiz: %c",arvore[pai].info);
   while(arvore[pai].info!= '-'){
       	printf("\nFilhos de %c: ", arvore[pai].info);
       	cont=0; qt =arvore[pai].nro_filhos;
       	for(i=1; i<=qt; i++){
           	if(arvore[posicao].info != '-'){
              printf("\t%c",arvore[posicao].info);
              cont++;}
           posicao++;}
       	if (cont==0) printf("....sem filhos");
       pai++;}
}

void mostra_vetor(def_arvore arvore){
     int i;
     printf("\n\n");
     for (i=0; i<Max; i++)
         printf("\narvore[%d] = %c  %d",i,arvore[i].info,arvore[i].nro_filhos);
}

int main(){
	def_arvore arvore;

   inicializa_arvore(arvore);
   le_arvore(arvore);
   escreve_arvore(arvore);
   mostra_vetor(arvore);
   printf("\n\n\aTecle algo para encerrar ...");getch();

}


