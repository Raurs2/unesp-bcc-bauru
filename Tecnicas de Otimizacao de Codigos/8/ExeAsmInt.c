#include <stdio.h>

int main() {
  int x = 10, y = 20, z = 30;
  int soma;

  asm("   MOV   ECX, %[x]\n"
      "   ADD   ECX, %[y]\n"
      "   ADD   ECX, %[z]\n"
      "   MOV   %[soma], ECX"
      : [soma] "=r"(soma)//saidas
      : [x] "r"(x), [y] "r"(y), [z] "r"(z)//entradas
      : "ecx");

  printf("%d\n", soma);

  return 0;
}
