#include<stdio.h>

#define max 10

typedef int pilha[max];
typedef pilha pilhas[max/2];

typedef struct no{
   int cep;
   char nome[20];
   no *prox;
} def_pilha;

typedef def_pilha conjP[10];

int desempilha(pilha p, int *x) {}
int empilha(pilha p, int x) {}

int busca(int x, pilhas p)
{
   int i, v, achou = 0;
   pilha aux;
   for ( i = 0; i < max/2; i++)
   {
      while (desempilha(p[i], &v))
      {
         
         if (v == x)
         {
            achou = 1;
         } else empilha(aux, v);
      }
      while (desempilha(aux, &v))
      {
         empilha(p[i], v);
      }
      if (achou)
      {
         return 1;
      }
   }
   return 0;
}

int main(int argc, char const *argv[])
{
   
   return 0;
}
