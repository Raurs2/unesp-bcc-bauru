#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------------------
float potI (float x, int y) {
  int i;
  float pot = 1;
  for (i = 1; i <= y; i++)
    pot *= x;     
  return pot;
}
//------------------------------------------------------------------------------
float potR (float x, int y) {
  if (y == 0)
    return 1;
  return x * potR(x,y-1);
}
//------------------------------------------------------------------------------
int main(){
  float n1;
  int n2;
  printf ("Digite um numero (base): ");
  scanf ("%f",&n1);
  do {
    printf ("Digite um numero inteiro positivo (expoente): ");
    scanf ("%d",&n2);
  } while (n2 < 0);
  printf ("\nIterativo - (%.1f)^%d = %.3f\n",n1,n2,potI(n1,n2));
  printf ("\nRecursivo - (%.1f)^%d = %.3f\n\n\n",n1,n2,potR(n1,n2));
  system ("pause");
}    
//------------------------------------------------------------------------------
