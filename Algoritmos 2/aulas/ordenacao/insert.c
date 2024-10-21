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
int insertSort (int n, int v[]) {
  int i, j, aux;
  for(i = 1; i < n; i++) {
    aux = v[i]; 
    for(j = i-1; (j >= 0) && (aux < v[j]); j--)
      v[j + 1] = v[j];
    v[j + 1] = aux;
  }  
}
//-------------------------------------------------------
int main () {
  int v[] = {10, -3, -7, 0, 6, 2, 1, 7};
  mostraVetor (8,v);
  insertSort (8,v);
  mostraVetor (8,v);
  getch();
}
