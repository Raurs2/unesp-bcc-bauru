#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#define MAX 3

typedef int def_pilha[MAX];

int empilha (def_pilha pilha, int *topo, int num){
  if (*topo == MAX-1) return 0;
  pilha[++(*topo)] = num;
  return 1;
}

int desempilha (def_pilha pilha, int *topo, int *num){
  if (*topo == -1) return 0;
  *num = pilha[(*topo)--];
  return 1;
}

void visualiza (def_pilha pilha, int topo){	
  int i=topo;
  
  if (topo >= 0)
    for(; i>=0; i--)printf("%d\n",pilha[i]);
  else printf(" esta vazia\n");
}

int main () {    
  def_pilha pilha1, pilha2;
  int topo1 = -1, topo2 = -1;
  int n, op, num, saiu, temCar;
  int x;
  
  printf("1 - Estacionar\n2 - Sair do estacionamento\n3 - Ver\n4 - Sair do programa\n");
  do
  {
  	x = 0;
    do
    {
      scanf("%d", &op);
    } while (op < 1 && op > 4);
    
    if (op == 1)
    {
      printf("CNH do motorista: ");
      scanf("%d", &n);
      if (empilha(pilha1, &topo1, n))
        printf("Estacionou\n");
      else printf("Sem vaga\n"); 
    } else if (op == 2)
    {
      printf("CNH do motorista: ");
      scanf("%d", &num);
      saiu = temCar = 0;
      do
      {
        temCar = desempilha(pilha1, &topo1, &n);
        x++;
        if (n == num)
        {
          saiu = 1;
          printf("Carro saiu do estacionamento\n");
        } else empilha(pilha2, &topo2, n);
        if (!temCar)
        {
          printf("Sem Carro no estacionamento\n");
        }
      } while (temCar && !saiu);
      
      while (desempilha(pilha2, &topo2, &n))
      {
        empilha(pilha1, &topo1, n);
        x++;
      }
      printf("Manobras: %d\n", x);
    } else if (op == 3)
    {
      visualiza(pilha1, topo1);
    }
  } while (op != 4);
  return 1;
}

