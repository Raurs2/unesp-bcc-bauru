#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Raul Alexandre

#define MAX 20

typedef float def_pilha[MAX];

int empilha (def_pilha pilha, int *topo, float num){
  if (*topo == MAX-1) return 0;
  pilha[++(*topo)] = num;
  return 1;
}

int desempilha (def_pilha pilha, int *topo, float *num){
  if (*topo == -1) return 0;
  *num = pilha[(*topo)--];
  return 1;
}

void visualiza (def_pilha pilha, int topo){	
  int i=topo;
  
  if (topo >= 0)
    for(; i>=0; i--)printf("%.2f\n",pilha[i]);
  else printf(" esta vazia\n");
}



int main () {    
  def_pilha pilha1, pilha2, pilha3;
  int topo1 = -1, topo2 = -1, topo3;
  float nota, num;
  
  printf("Notas 1\n");
  while (scanf("%f", &nota) != EOF)
  {
    empilha(pilha1, &topo1, nota);
  }

  printf("Notas 2\n");
  while (scanf("%f", &nota) != EOF)
  {
    empilha(pilha2, &topo2, nota);
  }
  
  while (desempilha(pilha2, &topo2, &num))
  {
    empilha(pilha3, &topo3, num);  
  }

  while (desempilha(pilha3, &topo3, &num))
  {
    empilha(pilha1, &topo1, num);
  }
  
  visualiza(pilha1, topo1);

  return 1;
}

