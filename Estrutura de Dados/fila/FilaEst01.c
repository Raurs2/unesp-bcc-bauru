/*
   Fila Estatica - Modelo 01 - Definicao 01
   A cada insercao e remocao implica em atualizar
        as vari‡veis início e fim
    Não há reuso do vetor
*/

#include <stdio.h>
#include <conio.h>

#define max  10

typedef int def_fila[max];

int vazia(int Inicio, int Final){
     return ((Inicio == -1) || (Inicio == Final+1));
}

int cheia(int Final){
     return (Final == max-1);
}

int enfileira (def_fila Fila, int *Inicio, int *Final, int x){
     if (cheia(*Final)) return 0;
     Fila[++(*Final)]=x;
     if ((*Inicio) == -1) (*Inicio) = 0;
     return 1;
}

int desenfileira (def_fila Fila, int* Inicio, int *Final, int *x){
     if (vazia(*Inicio,*Final)) return 0;
     *x=Fila[(*Inicio)];
     (*Inicio)++;
     return 1;
}

void visualiza (def_fila Fila, int Inicio, int Final){ 
     int i;

     for(i=Inicio; i<=Final; i++) printf("%d\t",Fila[i]);
     printf("\n");
}



void main(void){
     def_fila fila;
     int inicio, final,elemento,ok;
     char opcao;

     final=inicio=-1;
     if (vazia(inicio,final)) printf("Fila vazia \n");
     else{ printf("Fila com elementos\n");visualiza(fila,inicio,final);}
     do{
           printf("Inserir elemento (-1 para sair)= ");scanf("%d",&elemento);
           if (elemento != -1)
              if (!enfileira(fila,&inicio,&final,elemento)) printf("Nao inseriu\n");
     }while (elemento != -1);
     if (vazia(inicio,final)) printf("\nFila vazia\n");
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
     if (vazia(inicio,final)) printf("\nFila vazia\n");
     else {printf("Fila com elementos\n");visualiza(fila,inicio,final);}
     printf("\n\n\aTecle algo para encerrar");getch();
}
