#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Raul Alexandre

#define MAX 10

typedef char def_pilha[MAX];

int empilha (def_pilha pilha, int *topo, char word){
  if (*topo == MAX-1) return 0;
  pilha[++(*topo)] = word;
  return 1;
}

int desempilha (def_pilha pilha, int *topo, char *word){
  if (*topo == -1) return 0;
  *word = pilha[(*topo)--];
  return 1;
}

void visualiza (def_pilha pilha, int topo){	
  int i=topo;
  
  if (topo >= 0)
    for(; i>=0; i--)printf("%c\n",pilha[i]);
  else printf(" esta vazia\n");
}

int main () {    
  def_pilha pilha1, pilha2;
  int topo1 = -1, topo2 = -1;
  char opcao, word, palavra[10];
  
  scanf("%s", &palavra);
  
  int i = 0;
  while (palavra[i] != 'C')
  {
    empilha(pilha1, &topo1, palavra[i++]);
  }
  i++;
  
  while (palavra[i] != '\0')
  {
    desempilha(pilha1, &topo1, &word);

    if (palavra[i] != word)
    {
      printf("Palavra nao valida!\n");
      exit(1);
    }

    i++;
  }
  
  printf("Palavra valida!\n");

  return 1;
}

