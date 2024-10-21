#include <stdio.h>
int quadrado(int x);
//-------------------------------------------------------
int main() {
  int i = 10;
  printf("%d = %d^2",quadrado(i),i);
}
//-------------------------------------------------------
int quadrado(int x) {
  return x*x;
}

