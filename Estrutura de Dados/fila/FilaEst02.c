/*
   Fila Estatica - Modelo 02 - Definicao 01
   Cada remocao da Fila implicar‡ no deslocamento de todos os elementos
        para o início da Fila

*/

#include <stdio.h>
#include <conio.h>

#define max  10

typedef int def_fila[max];

int vazia(int Final){
     return (Final == -1);
}

int cheia(int Final){
     return (Final == max-1);
}

int enfileira (def_fila Fila, int *Final, int x){
     if (cheia(*Final)) return 0;
     Fila[++(*Final)]=x;
     return 1;
}

int desenfileira (def_fila Fila, int* Final, int* x){    
     int i;
     if (vazia(*Final)) return 0;
     *x=Fila[0];
     for (i=0; i<=*Final; i++) Fila[i]=Fila[i+1];
     (*Final)--;
     return 1;
}

void visualiza(def_fila Fila, int Final){ 
     int i;

     for(i=0; i<=Final; i++) printf("%d\t",Fila[i]);
     printf("\n");
}



void main(void){
def_fila fila;
int final, elemento,ok;
char opcao;

     final=-1;
     do{
           printf("Inserir elemento (-1 para sair)= ");scanf("%d",&elemento);
           if (elemento != -1)
              if (!enfileira(fila,&final,elemento)) printf("Nao inseriu\n");
     }while (elemento != -1);
     if (vazia(final)) printf("Fila vazia\n");
     else {printf("Fila com elementos\n");visualiza(fila,final);}
     ok=1;
     do{
           printf("\nRemover elemento?(S/N) ");opcao=getche();
           if (opcao == 's' || opcao == 'S') {
              if (desenfileira(fila,&final,&elemento)) printf("\tremoveu %d \n",elemento);
              else ok=0;}
           else ok=0;
     }while (ok!=0);
     if (vazia(final)) printf("Fila vazia\n");
     else {printf("Fila com elementos\n");visualiza(fila,final);}
     printf("\n\n\aTecle algo para encerrar");getch();
}
