#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Raul Alexandre

#define MAX 3

typedef float pilhaNum[MAX];
typedef char operacao[MAX+1];

int empilha (pilhaNum pilha, int *topo, float num){
  if (*topo == MAX-1) return 0;
  pilha[++(*topo)] = num;
  return 1;
}

int desempilha (pilhaNum pilha, int *topo, float *num){
  if (*topo == -1) return 0;
  *num = pilha[(*topo)--];
  return 1;
}

void visualiza (pilhaNum pilha, int topo){	
  int i=topo;
  
  if (topo >= 0)
    for(; i>=0; i--)printf("%.2f\n",pilha[i]);
  else printf(" esta vazia\n");
}

int empilhaChar (operacao pilha, int *topo, char num){
  if (*topo == MAX-1) return 0;
  pilha[++(*topo)] = num;
  return 1;
}

int desempilhaChar (operacao pilha, int *topo, char *num){
  if (*topo == -1) return 0;
  *num = pilha[(*topo)--];
  return 1;
}

void visualizaChar (operacao pilha, int topo){	
  int i=topo;
  
  if (topo >= 0)
    for(; i>=0; i--)printf("%c\n",pilha[i]);
  else printf(" esta vazia\n");
}



int main () {    
  pilhaNum pilha1, pilha2, resultado, aux;
  operacao pilha3;
  int topo1 = -1, topo2 = -1, topo3 = -1, rTopo = -1, auxTopo = -1;
  float nota, n1, n2;
  char op;
  
  printf("Notas 1\n");
  int i = 0;
  for ( i = 0; i < MAX; i++)
  {
    scanf("%f", &nota);
    empilha(pilha1, &topo1, nota);
  }

  //visualiza(pilha1, topo1);

  printf("Notas 2\n");
  for ( i = 0; i < MAX; i++)
  {
    scanf("%f", &nota);
    empilha(pilha2, &topo2, nota);
  }

  //visualiza(pilha2, topo2);

  getchar();

  printf("Operacao\n");
  for ( i = 0; i < MAX; i++)
  {
    scanf("%c", &op);
    fflush(stdin);
    empilhaChar(pilha3, &topo3, op);
  }

  //visualizaChar(pilha3, topo3);

  for ( i = 0; i < MAX; i++)
  {
    desempilha(pilha1, &topo1, &n1);
    desempilha(pilha2, &topo2, &n2);
    desempilhaChar(pilha3, &topo3, &op);

    if (op == '+') nota = n1 + n2;
    else if (op == '-') nota = n1 - n2;
    else if (op == '*') nota = n1 * n2;

    empilha(aux, &auxTopo, nota);
  }

  visualiza(aux, auxTopo);

  printf("\n");

  for ( i = 0; i < MAX; i++)
  {
    desempilha(aux, &auxTopo, &nota);
    empilha(resultado, &rTopo, nota);
  }
  
  //visualiza(pilha1, topo1);
  //visualizaChar(pilha3, topo3);
  //visualiza(pilha2, topo2);
  visualiza(resultado, rTopo);
  

  return 1;
}

