#include <stdlib.h>
#include <stdio.h>

typedef struct pilhaReg *pilhaNo;
struct pilhaReg {
           int data;
           struct pilhaReg *prox;
};

void vizualiza (pilhaNo pilha) {
  if (pilha == NULL) {
      printf ("\nPilha vazia"); 
      return;          
  }   
  pilhaNo p = pilha;
  printf ("\nElementos da pilha: ");
  do {
    printf ("%d ",p->data);
    p = p->prox;
  } while (p != pilha);
 }

void empilha (pilhaNo *pilha, int data) {
  pilhaNo p = (pilhaNo) malloc(sizeof(struct pilhaReg));
  p->data = data;
  if (!*pilha) {  
       p->prox = p;
       *pilha = p;
  }    
  else {
      pilhaNo q = *pilha; 
      while (q->prox != *pilha)
        q = q->prox;
      q->prox = p;
      p->prox = *pilha;   
      *pilha = p;
  }
}

int desempilha (pilhaNo *pilha) {
  if (!*pilha)
    return 0;
  if ((*pilha)->prox == *pilha) {  
      free (*pilha);
      *pilha = NULL;                 
  }  
  else {
      pilhaNo q = *pilha;
      while (q->prox != *pilha)
        q = q->prox;
      pilhaNo p = *pilha;
      *pilha = p->prox;
      q->prox = *pilha;
      free (p);
  }  
  return 1;
}

int main()
{
    pilhaNo pilha = NULL;
    int op;
    
    printf("Empilha -1 para\n");
    do
    {
      scanf("%d", &op);
      empilha(&pilha, op);
    } while (op != -1);
    
    visualiza(pilha);

    printf("Desempilha -1 para\n");
    do
    {
      scanf("%d", &op);
      if (desempilha(&pilha)) printf("Sucesso!\n");
      else printf("Erro!\n");
    } while (op != -1);

    visualiza(pilha);

    return 0;
}
