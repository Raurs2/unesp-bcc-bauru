/*
   Apostila
   Exercício 02 - Pilha estática (2 pilhas numa só)

*/

#include <stdio.h>
#include <conio.h>

#define max 10

typedef struct{
                int topo1, topo2;
                int elementos[max];} def_pilha;


int vazia (def_pilha Pilha, int qual){
     if (qual==1) return (Pilha.topo1 == -1);
     else return (Pilha.topo2 == max);
}

int cheia(def_pilha Pilha){
        if((Pilha.topo1 == Pilha.topo2-1) || ((Pilha.topo1 + Pilha.topo2) == -1)) return (1);
        return 0;
}

int empilha (int x, def_pilha *Pilha, int qual){
	  if (cheia(*Pilha)) return 0;
     if (qual == 1){
        if (Pilha->topo1 < Pilha->topo2-1){
           Pilha->elementos[++(Pilha->topo1)]=x;
           return 1; }
        return 0;}
     else{
        if (Pilha->topo2 > Pilha->topo1+1){
           Pilha->elementos[--(Pilha->topo2)]=x;
           return 1;}
        return 0;}
}

int desempilha (def_pilha *Pilha, int* x, int qual){
     if (qual == 1){
        if (!vazia(*Pilha,qual)){
            *x = Pilha->elementos[(Pilha->topo1)--];
            return 1;}
        return 0;}
     else{
        if (!vazia(*Pilha,qual)){
            *x = Pilha->elementos[(Pilha->topo2)++];
            return 1;}
        return 0;}
}


void mostra (def_pilha Pilha){
     int i;
     if (!vazia(Pilha,1)){
        printf("A pilha1 esta com os elementos ...\n");
        for(i=Pilha.topo1;i>=0;i--) printf("%d\t",Pilha.elementos[i]);}
     printf("\n");        
     if (! vazia(Pilha,2)){
        printf("A pilha2 esta com os elementos ...\n");
        for(i=Pilha.topo2;i<max;i++) printf("%d\t",Pilha.elementos[i]);}
     printf("\n\n");
}

void main (void)
{	def_pilha pilha;
   int qual,elemento,pode,ok;
   char opcao;

     pilha.topo1 = -1;
	 pilha.topo2 = max;
     if (vazia(pilha,1)) printf("A Pilha1 est  vazia\n");
     else printf("A Pilha1 est  com elementos\n");
     if (vazia(pilha,2)) printf("A Pilha2 est  vazia\n");
     else printf("A Pilha2 est  com elementos\n");
     do{ pode = 1;
           printf("empilhar elemento = ");scanf("%d",&elemento);
           if (elemento != -1){
              printf("empilhar em pilha 1 ou 2 = ");scanf("%d",&qual);
              pode=empilha(elemento,&pilha,qual);
              if (!pode) printf("nao empilhou\n");}
     }while (elemento != -1 && pode);
     if (vazia(pilha,1)) printf("Pilha1 vazia apos empilhamento\n");
     if (vazia(pilha,2)) printf("Pilha2 vazia apos empilhamento\n");
     mostra(pilha);
     ok=1;
     do{
           printf("desempilhar elemento?(S/N) ");opcao=getche();
           if (opcao =='s' || opcao =='S'){
              printf("desempilhar da pilha 1 ou 2 = ");scanf("%d",&qual);
              if (desempilha(&pilha,&elemento,qual)) printf("desempilhou %d\n",elemento);
              else ok=0;}
           else ok=0;
     }while (ok!=0);
     if (vazia(pilha,1)) printf("Pilha1 vazia apos desempilhamento\n");
     if (vazia(pilha,2)) printf("Pilha2 vazia apos desempilhamento\n");
     mostra(pilha);
     printf("\n\n\aDigite algo para encerrar ... ");getch();
}
