#include <stdio.h>
#include <stdlib.h>
// Busca iterativa no vetor nao ordenado
int busca (int n, int *v, int num) {  
    int i;
    for (i = 0; i < n; i++)
          if (v[i]== num)
             return i;
    return -1;
}
// Busca recursiva no vetor nao ordenado
int buscaR (int n, int *v, int num) {  
    if (n == 0)
       return -1;
    if (v[n-1] == num)
       return n-1;
    return buscaR (n-1,v,num);
}
// Busca iterativa no vetor ordenado
int buscaO (int n, int *v, int num) {  
    int i;
    for (i = 0; i < n && v[i] <= num; i++)
        if (v[i]== num)
           return i;
     return -1;
}
// Busca recursiva no vetor ordenado
int buscaOR (int n, int *v, int num) {  
    if (n == 0 || num > v[n])
       return -1;
    if (v[n-1] == num)
       return n-1;
    return buscaOR (n-1,v,num);
}
// Busca bin�ria iterativa - vetor ordenado
int BuscaBin (int n, int *v, int num) {
  int meio, esq=0, dir=n-1;
  while (esq <= dir) {
    meio = (esq+dir)/2;
    if (v[meio] == num)
      return meio;
    if (num > v[meio])
      esq = meio+1;
    else 
      dir = meio-1;
  }
  return -1;
}
// Busca bin�ria recursiva - vetor ordenado
int BuscaBinR (int *v, int esq, int dir, int num) {
    if (esq > dir)
       return -1;
    int meio = (esq+dir)/2;       
    if (v[meio] == num)
       return meio;
    if (num > v[meio])
       return BuscaBinR (v,meio+1,dir,num);
    return BuscaBinR (v,esq,meio-1,num);
}
// Programa Principal
int main () {
//    int vetor [] = {120, 230, 40, 55, 89, 101};
  int vetor [] = {12, 23, 40, 55, 89, 101 };    
  int tam = 6, elem = 23;
  // Iterativos
  printf ("---> %d\n\n\n",busca (tam,vetor,elem));
  printf ("---> %d\n\n\n",buscaO (tam,vetor,elem));    
  printf ("---> %d\n\n\n",BuscaBin (tam,vetor,elem));
  // Recursivos
  printf ("---> %d\n\n\n",buscaR (tam-1,vetor,elem));
  printf ("---> %d\n\n\n",buscaOR (tam-1,vetor,elem));
  printf ("---> %d\n\n\n",BuscaBinR (vetor,0,tam-1,elem));
}
