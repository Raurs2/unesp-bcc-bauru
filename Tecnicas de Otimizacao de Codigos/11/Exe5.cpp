#include <cstdio>
#include <cstring>

int par1(short int x) {
  int res = 0;
  asm("   mov   ax, %[x]    \n"
      "   shr   ax, 1       \n"
      "   jc    salta1_%=   \n"
      "   mov   eax, 1      \n"
      "salta1_%=:"
      "   jnc   salta2_%=   \n"
      "   mov   eax, 0      \n"
      "salta2_%=:"
      "   mov   %[res], eax \n"
      : [res] "=r"(res)
      : [x] "r"(x)
      : "rax");
  return res;
}

int par2(short int x) {
  int res = 0;
  asm("   mov   ax, %[x]    \n"
      "   mov   ebx, 0      \n"
      "   shr   ax, 1       \n"
      "   jc    salta1_%=   \n"
      "   mov   ebx, 1      \n"
      "salta1_%=:"
      "   mov   %[res], ebx \n"
      : [res] "=r"(res)
      : [x] "r"(x)
      : "rax", "rbx");
  return res;
}

int par3(short int x) {
  int res = 0;
  asm("   mov   ax, %[x]    \n"
      "   xor   ebx, ebx    \n"
      "   shr   ax, 1       \n"
      "   jc    salta1_%=   \n"
      "   mov   ebx, 1      \n"
      "salta1_%=:"
      "   mov   %[res], ebx \n"
      : [res] "=r"(res)
      : [x] "r"(x)
      : "rax", "rbx");
  return res;
}

int par(short int x) {
  int res = 0;
  asm("   mov   ax, %[x]    \n"
      "   shr   ax, 1       \n"
      "   mov   eax, 0      \n"
      "   adc   eax, eax    \n"
      "   xor   eax, 1      \n"
      "   mov   %[res], eax \n"
      : [res] "=r"(res)
      : [x] "r"(x)
      : "rax");
  return res;
}

int main() {
  int x = 34252;
  printf("%d %d\n", 10, par(10));
  printf("%d %d\n", 11, par(11));
  printf("%d %d\n", 12346, par(12346));
  printf("%d %d\n", 12343, par(12343));
  return 0;
}