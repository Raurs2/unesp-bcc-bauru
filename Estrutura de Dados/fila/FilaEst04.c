/*
   Fila Est‡tica - Modelo 04 - Definicao 01
   Fila circular

*/

#include <stdio.h>
#include <conio.h>

#define max  10

typedef int def_fila[max];

int vazia(int Inicio){
     return (Inicio == -1);
}

int cheia(int Inicio, int Final){
   if (Final>Inicio && Inicio==0 && Final==max-1)return 1;
   return (Final == Inicio-1);
}


int enfileira (def_fila Fila, int *Inicio, int *Final,int x){
     if (cheia(*Inicio,*Final)) return 0;
     (*Final)++;
     if(*Final == max) *Final=0;
     Fila[(*Final)]=x;
     if ((*Inicio) == -1) (*Inicio) = 0;
     return 1;
}

int desenfileira (def_fila Fila, int* Inicio, int *Final, int* x){
     if (vazia(*Inicio)) return 0;
     *x=Fila[(*Inicio)];
     if(*Inicio==*Final) *Inicio=*Final=-1; // ultimo elemento
     else 
          if(*Inicio == max-1) *Inicio=0; 
          else (*Inicio)++;
     return 1;
}

void visualiza(def_fila Fila, int Inicio, int Final)
{ int i;

     if (Final>=Inicio)
     		for(i=Inicio; i<=Final; i++)printf("[%d]%d\t",i,Fila[i]);
     else{
           for(i=Inicio; i<max; i++)printf("[%d]%d\t",i,Fila[i]);
           for(i=0; i<=Final; i++)printf("[%d]%d\t",i,Fila[i]);}
     printf("\n");
}



void main(void){
	def_fila fila;
	int inicio, final,elemento,ok;
	char opcao,opcao1;

   inicio=final=-1;
   do{
     printf("\n\n\nA.Inserir\nB.Remover\nC.Sair\n\n=>");
     opcao=getche();
     printf("\n\n");
     if (opcao=='A' || opcao =='a'){
         do{
           printf("Inserir elemento (-1 para sair)= ");scanf("%d",&elemento);
           if (elemento != -1)
              if (!enfileira(fila,&inicio,&final,elemento)) printf("Nao inseriu\n");
     		}while (elemento != -1);
     		if (vazia(inicio)) printf("\nFila vazia\n");
     		else {printf("Fila com elementos\n");visualiza(fila,inicio,final);}
     }
     if (opcao=='B'|| opcao =='b'){
     ok=1;
     do{
           printf("Remover elemento?(S/N) ");opcao1=getche();
           if (opcao1 == 's' || opcao1 == 'S') {
              if (desenfileira(fila,&inicio,&final,&elemento)) printf("\tremoveu %d \n",elemento);
              else ok=0;}
           else ok=0;
     }while (ok!=0);
     if (vazia(inicio)) printf("\nFila vazia\n");
     else {printf("Fila com elementos\n");visualiza(fila,inicio,final);}
     }
   }while (opcao!='C' && opcao !='c');
     printf("\n\n\aTecle algo para encerrar");getch();
}
