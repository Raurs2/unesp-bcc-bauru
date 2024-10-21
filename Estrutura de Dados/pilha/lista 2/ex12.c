#include <stdlib.h>
#include <stdio.h>

//Raul Alexandre

typedef struct no_pilha {
  int data;
  struct no_pilha *prox;
} *def_pilha;

void empilha (def_pilha *pilha, int data) {
  def_pilha p = (def_pilha) malloc(sizeof(struct no_pilha));

  p->data = data;
  if (!*pilha) { //verifica se eh vazia
    p->prox = p;
    *pilha = p;
  }    
  else {
    def_pilha q = *pilha;

    while (q->prox != *pilha) q = q->prox;

    q->prox = p;
    p->prox = *pilha;   
    *pilha = p;
  }
}

int desempilha (def_pilha *pilha) {
  if (!*pilha) return 0;

  if ((*pilha)->prox == *pilha) {
    free (*pilha);
    *pilha = NULL;                 
  }  
  else {
    def_pilha q = *pilha;

    while (q->prox != *pilha) q = q->prox;

    def_pilha p = *pilha;
    *pilha = p->prox;
    q->prox = *pilha;
    free (p);
  }  
  return 1;
}

int visualiza (def_pilha pilha) {
  if (pilha == NULL) return 0; 

  def_pilha p = pilha;

  do {
    printf("%d ", p->data);
    p = p->prox;
  } while (p != pilha);
  return 1;
 }

int main()
{
    def_pilha pilha = NULL;
    int op;
    
    printf("Empilha -1 para\n");
    do
    {
      scanf("%d", &op);
      if (op == -1) break;
      empilha(&pilha, op);
    } while (op != -1);
    
    visualiza(pilha);

    printf("\nDesempilha -1 para\n");
    do
    {
      scanf("%d", &op);
      if (op == -1) break;
      if (desempilha(&pilha)) printf("Sucesso!\n");
      else printf("Vazio!\n");
    } while (op != -1);

    visualiza(pilha);

    return 0;
}
