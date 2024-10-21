#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------------
void mostraVetor (int n, int v[]){
  int i;
  printf ("\nVetor: \n");
  for (i = 0; i < n; i++)	
    printf ("%d  ",v[i]);
  printf ("\n");  
}
//-------------------------------------------------------
int selectSort_v1 (int n, int v[]) {
  int aux, i, j;
  for (i = 0; i < n-1; i++)
    for (j = i+1; j < n; j++)
      if (v[i] > v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
}
//-------------------------------------------------------
int selectSort_v2 (int n, int v[]){
  int aux, i, j, pos_menor;
  for (i = 0; i < n-1; i++) {
    pos_menor = i;  // indice do menor elemento 
    for(j = i+1; j < n; j++)
      if (v[j] < v[pos_menor])
        pos_menor = j;
    if (pos_menor != i){
      aux = v[i];
      v[i] = v[pos_menor];
      v[pos_menor] = aux;
    }
  }
}
//-------------------------------------------------------
int selecao_maior (int n, int v[]){
  int aux, i, j, pos_maior;
  for (i = 0; i < n-1; i++) {
    pos_maior = 0;
    for(j = 1; j < n-i; j++)
      if (v[j] > v[pos_maior])
        pos_maior = j;
    if (pos_maior != n-i-1){
      aux = v[n-i-1];
      v[n-i-1] = v[pos_maior];
      v[pos_maior] = aux;
    }
  }
}
//-------------------------------------------------------
int main () {
  int v[] = {10, -3, -7, 0, 6, 2, 1, 7};
  mostraVetor (8,v);
  selecao_maior (8,v);
  mostraVetor (8,v);
}
