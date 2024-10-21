#include<stdio.h>

#define max 10

typedef int fila[max];
typedef fila filas[max/2];

typedef struct  no
{
    int tipo;
    int caminho;
    struct 
} *def_fila;


int desenfileira(fila p, int *x) {}
int enfileira(fila p, int x) {}

int busca(int x, filas p)
{
   int i, v, achou = 0;
   fila aux;
   for ( i = 0; i < max/2; i++)
   {
      while (desenfileira(p[i], &v))
      {
         
         if (v == x)
         {
            achou = 1;
         } else enfileira(aux, v);
      }
      while (desenfileira(aux, &v))
      {
         enfileira(p[i], v);
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
