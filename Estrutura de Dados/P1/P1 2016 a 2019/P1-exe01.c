/*
  Pilha estática
					   pilha[0] = topo
					   pilha[1] a pilha[max-1] = elementos
*/

#include <stdio.h>
#include <conio.h>
#define N 11

typedef int sacola[N];
typedef sacola conj_sacolas[5];



int vazia (sacola Pilha){
     	return (Pilha[0] == 0);
}

int cheia (sacola Pilha){
     	return (Pilha[0] == N-1 );
}

int empilha (sacola Pilha, int x){
     	if(cheia(Pilha)) return 0;
        Pilha[++(Pilha[0])]=x;
        return 1;
}

int desempilha (sacola Pilha, int* x){
     	if (vazia(Pilha)) return 0;
        *x = Pilha[(Pilha[0])--];
        return 1;
}

void mostra_sacola (sacola Pilha)
{	int i=Pilha[0];
	if (i >= 0){
     for(; i>0; i--)printf("\t%d",Pilha[i]);}
   else printf(" esta vazia");
}

int busca (conj_sacolas Pilhas, int x){
    int i, nro, encontrou=0;
    sacola aux;
    
    for(i=0;i<5 && encontrou ==0;i++){
         aux[0]=0; encontrou = 0;
         while(encontrou==0 && desempilha(Pilhas[i], &nro)){
               if(nro==x) encontrou=1; 
               else empilha(aux,nro);
               }
         while(desempilha(aux,&nro)) empilha(Pilhas[i],nro);      
         }
    return encontrou;    
}

int main (void){    
      conj_sacolas estadio;
 	  int elemento, ok, i,sac=0;
	  char opcao;

     for(i=0; i<5; i++) estadio[i][0]=0;
     do{
           printf("Guardar bola = ");
           scanf("%d",&elemento);
           
           if (elemento != -1){
               printf("Na sacola = ");
               scanf("%d",&sac);
               if(empilha(estadio[sac],elemento)) printf(" Guardou na sacola %d\n",sac);
               else printf("\n Não colocou na sacola %d",sac);
              }
     }while (elemento != -1);

     for(i=0;i<5; i++){
        if(!vazia(estadio[i])){
           printf("\nSacola %d com elementos:  ",i);
           mostra_sacola(estadio[i]);}}

  
      printf("\nBuscar bola?(S/N) ");
      opcao=getche();
      if (opcao == 's' || opcao == 'S'){
           printf("Qual bola = ");
           scanf("%d",&elemento);
           if (busca(estadio, elemento)) printf("\nachou a bola\n");
           else printf("\n\nNao ");}
    
    for(i=0;i<5; i++){
        if(!vazia(estadio[i])){
           printf("\nSacola %d com elementos:  ",i);
           mostra_sacola(estadio[i]);}}
     printf("\n\nTermino do Desempilhamento\n----\n");
 

    
     printf("\n\n\aDigite algo para encerrar ... ");getch();
     return 1;
}

