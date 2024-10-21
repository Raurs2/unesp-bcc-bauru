// Escreva uma função que classifique um conjunto alfanumérico em ordem crescente.

#include <stdio.h>
#include <string.h>

void troca (char n1[], char n2 []) {
  char aux[10];
  strcpy (aux,n1);
  strcpy (n1,n2);
  strcpy (n2,aux);
}  
//-------------------------------------------------------------
void BubbleSort (int n, char v[][10]) {
  int i, j, aux;
  int trocado = 1;
  for (i=0; i<n-1 && trocado; i++) {
    trocado = 0;
    for (j=0; j<n-i-1; j++) {
      if (stricmp(v[j],v[j+1])>0) {
        trocado = 1;
        troca (v[j], v[j+1]);
      }
    }
  }
}
//-------------------------------------------------------------
int main () {
  char nomes[5][10]={"bbbbb","CCCCC","aaaaa","eeeeee","dddddd"};
  int i; 
  for (i = 0; i < 5; i++)
    printf ("%s  ",nomes[i]);
  BubbleSort (5,nomes);
  printf ("\n");
  for (i = 0; i < 5; i++)
    printf ("%s  ",nomes[i]);
}

