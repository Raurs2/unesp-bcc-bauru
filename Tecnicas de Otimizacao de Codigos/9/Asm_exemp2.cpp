#include <stdio.h>
int v[1000];
int main() {
  int var = 123;
  asm("  push rax      \n"
      "  mov eax, %[var]\n"
      "  pop rax  \n"
      :
      : [var] "r" (var));
  printf("%d %d %d\n", v[0], v[1], v[2]);
  return 0;
}
