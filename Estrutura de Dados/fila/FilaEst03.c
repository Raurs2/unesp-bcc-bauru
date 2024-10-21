/*
   Fila Estática - Modelo 03 - Definição 01
   A cada insercao e remocao da Fila implica em atualizar
        as variáveis inÌcio e fim
   Quando fim atingir Max, desloca-se os elementos para
   o inicio.

*/

#include <stdio.h>
#include <conio.h>

#define max  10

typedef int def_fila[max];

int vazia(int Inicio, int Final){
    return ((Inicio == -1) || (Inicio == Final+1));
}

int cheia(int Inicio, int Final){
     return !((Final-Inicio+1) < max);
}


int enfileira (def_fila Fila, int *Inicio, int *Final, int x){ 
     int i;
     if (cheia(*Inicio, *Final)) return 0;
     (*Final)++;
     if (*Final == max){
         for(i=0;i<*Final;i++) Fila[i] = Fila[(*Inicio)+i];
         (*Final) -= (*Inicio);
    	 (*Inicio) = 0;}
    Fila[(*Final)]=x;
    if ((*Inicio) == -1) {
(*Inicio) = 0; printf("\n primeiro elemento %d  %d",*Inicio,*Final);}
    return 1;
}

int desenfileira (def_fila Fila, int* Inicio, int *Final, int* x){
     if (vazia(*Inicio,*Final)) return 0;
     *x=Fila[(*Inicio)];
     Fila[(*Inicio)++]=-1;
     return 1;
}

void visualiza (def_fila Fila, int Inicio, int Final){ 
     int i;

     if (Final >= Inicio) {
	     for(i=Inicio; i<=Final; i++) printf("%d\t",Fila[i]);}
     else{
	     for(i=Inicio; i<max; i++) printf("%d\t",Fila[i]);
	     for(i=0; i<=Final; i++) printf("%d\t",Fila[i]);
		 }
     printf("\n");
}



void main(void){
     def_fila fila;
     int inicio, final, elemento,ok;
     char opcao;

     inicio=final=-1;

     do{
           printf("Inserir elemento (-1 para sair)= ");scanf("%d",&elemento);
           if (elemento != -1)
              if (!enfileira(fila,&inicio,&final,elemento)) printf("Nao inseriu\n");
     }while (elemento != -1);

     if (vazia(inicio,final)) printf("Fila vazia\n");
     else {printf("Fila com elementos\n");visualiza(fila,inicio,final);}
     ok=1;
     do{
           printf("\nRemover elemento?(S/N) ");opcao=getche();
           if (opcao == 's' || opcao == 'S') {
              if (desenfileira(fila,&inicio,&final,&elemento))         
                  printf("\tremoveu %d \n",elemento);
              else ok=0;}
           else ok=0;
     }while (ok!=0);
     if (vazia(inicio,final)) printf("Fila vazia\n");
     else {printf("Fila com elementos\n");visualiza(fila,inicio,final);}
         
     printf("\n\n\aTecle algo para encerrar");getch();
}
