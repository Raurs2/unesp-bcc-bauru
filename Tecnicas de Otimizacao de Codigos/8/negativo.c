#include <stdio.h>

int main() {
  unsigned char x = 10, y = 20, z = 30;
  unsigned char soma;

  asm("   MOV   AL, %[x]\n"
      "   ADD   AL, %[y]\n"
      "   ADD   AL, %[z]\n"
      "   MOV   %[soma], AL"
      : [soma] "=r"(soma)//saidas
      : [x] "r"(x), [y] "r"(y), [z] "r"(z)//entradas
      : "al");

  printf("%d\n", soma);

  return 0;
}
