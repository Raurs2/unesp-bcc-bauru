/* 	Árvore Estática
		representação do tipo 01

*/

#include <stdio.h>
#include <conio.h>

#define Max 30
#define Grau 3

typedef char def_arvore[Max];

void inicializa(def_arvore arvore){
	int i;
    for (i=0; i<Max; i++) arvore[i]='-';
}

void le_arvore (def_arvore arvore){
	int posicao=1,i,pai=0,j,qt;
   char filho, tem_filhos;

   printf("Raiz: ");arvore[pai]=getche();
   for (j=1; j<Max; j++){
   	 if (arvore[pai]!= '-'){
       	  printf("\n\nO no %c tem filhos(s/n)?",arvore[pai]);
       	  tem_filhos=getche();
       	  if(tem_filhos =='s' || tem_filhos == 'S'){
	       		printf("\nLeitura dos filhos de: %c (Digite 0 se não tem filho)", arvore[pai]);
			    printf("\nQuantos filhos: ");qt=getche()-48;
   	    		for(i=1; i<=qt; i++){
      	     		printf("\nFilho = ");filho=getche();
           	  		if (filho!='0')arvore[posicao]=filho;
              		posicao++;}
                if(Grau>qt)	posicao+=(Grau-qt);
       	  		}
       	  else{posicao+=3;}
       	  }
       pai++;}
}

void escreve_arvore(def_arvore arvore){
	int posicao,i,pai=0,cont;

   if(arvore[0]== '-'){
     printf("\n\n\aArvore vazia...");return;}

	printf("\n\n\aImpressao da arvore: \n");
   printf("Raiz: %c",arvore[pai]);
   for (posicao=1; posicao<Max; posicao++){
	    if(arvore[pai]!= '-'){
       	printf("\nFilhos de %c: ", arvore[pai]);
       	cont=0;
       	for(i=1; i<=Grau; i++){
           	if(arvore[posicao] != '-'){
              printf("\t%c",arvore[posicao]);
              cont++;}
           posicao++;}
       if (cont==0) printf("....sem filhos");
       posicao--;}
       pai++;}
}

void mostra_vetor(def_arvore arvore){
     int i;
     printf("\n\n");
     for (i=0; i<Max; i++)
         printf("\narvore[%d] = %c",i,arvore[i]);
}
int main(){
	def_arvore arvore;

   inicializa(arvore);
   le_arvore(arvore);
   escreve_arvore(arvore);
   mostra_vetor(arvore);
   printf("\n\n\aTecle algo para encerrar ...");getch();
}
