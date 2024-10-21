#include <stdio.h>
int quadrado(int x);
//-------------------------------------------------------
int main() {
  int i = 10;
  for (i= 1; i < 10; i++)
    printf("%d = %d^2\n",quadrado(i),i);
}
//-------------------------------------------------------
int quadrado(int x) {
  return (x*x);
}

