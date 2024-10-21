#include <stdio.h>

int main() {
  char x = 10, y = 20, z = 30;
  char soma;

  asm("   MOV   R8B, %[x]\n"
      "   ADD   R8B, %[y]\n"
      "   ADD   R8B, %[z]\n"
      "   MOV   %[soma], R8B"
      : [soma] "=r"(soma)//saidas
      : [x] "r"(x), [y] "r"(y), [z] "r"(z)//entradas
      : "r8");

  printf("%d\n", soma);

  return 0;
}
