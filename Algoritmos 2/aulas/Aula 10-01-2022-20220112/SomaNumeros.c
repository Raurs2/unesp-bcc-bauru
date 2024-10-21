#include <stdio.h>
#include <stdlib.h>
//----------------------------------------
int somaI (int n) {
  int i, s = 0;
  for (i = 1; i <= n; i++)
    s += i;
  return s;
}
//----------------------------------------
int somaR (int n) {
  if (n == 0)
    return 0;
  return n + somaR(n-1);
}
//----------------------------------------
int main(){
  int valor;
  printf ("Digite um numero: ");
  scanf ("%d",&valor);
  printf ("\nSoma iterativa de 0 a %d: %d\n",valor,somaI(valor));
  printf ("\nSoma recursiva de 0 a %d: %d\n",valor,somaR(valor));   
}    
    
