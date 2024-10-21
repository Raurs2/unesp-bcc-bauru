#include <stdio.h>
//----------------------------------------
int mdcI (int a, int b) {
  int aux;
  while (a % b != 0){
    aux = a % b;
    a = b;
    b = aux;
  }     
  return b;
}
//----------------------------------------
int mdcR (int a, int b) {
  if (a % b == 0)
    return b;
  return mdcR (b, a % b);
}
//----------------------------------------
int main(){
    int n1, n2;
    printf ("Digite dois numeros: ");
    scanf ("%d %d",&n1,&n2);
    printf ("\nIterativo - m.d.c.(%d,%d) = %d\n",n1,n2,mdcI(n1,n2));
    printf ("\nRecursivo - m.d.c.(%d,%d) = %d\n",n1,n2,mdcR(n1,n2));   
}    
//----------------------------------------    
