#include <stdio.h>

int main() {
  short int x = 10, y = 20, z = 30;
  short int soma;

  asm("   MOV   CX, %[x]\n"
      "   ADD   CX, %[y]\n"
      "   ADD   CX, %[z]\n"
      "   MOV   %[soma], CX"
      : [soma] "=r"(soma)//saidas
      : [x] "r"(x), [y] "r"(y), [z] "r"(z)//entradas
      : "cx");

  printf("%d\n", soma);

  return 0;
}
