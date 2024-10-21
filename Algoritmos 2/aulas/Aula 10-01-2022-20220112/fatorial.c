#include <stdio.h>
//----------------------------------------
double fatI (int n) {
  int i;
  double aux = 1;
  for (i = 2; i <= n; i++)
      aux *= i;
  return aux;
}
//----------------------------------------
double fat (int n) {
  if (n <= 1)
     return 1;
  return n * fat(n-1);
}
//----------------------------------------
int main(){
  int valor;
  printf ("Digite um numero: ");
  scanf ("%d",&valor);
  printf ("\n\n\nIterativo: %d! = %.0lf\n",valor,fatI(valor));
  printf ("\nRecursivo: %d! = %.0lf\n",valor,fat(valor));   
}    
    
