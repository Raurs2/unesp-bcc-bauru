#include <cstdio>
#include <cstring>

int dividePor32_1(unsigned int x) {
  return x >> 5;
}

int restoDaDividePor32(unsigned int x) {
  return x & 0b11111;
}

int dividePor32(unsigned int x) {
  int res;
  asm("   mov   eax, %[x]   \n"
      "   shr   eax, 5      \n"
      "   mov   %[res], eax \n"
      : [res] "=r"(res)
      : [x] "r"(x)
      : "rax");
  return res;
}

int dividePor32Sinal(int x) {
  int res;
  asm("   mov   eax, %[x]   \n"
      "   sar   eax, 5      \n"
      "   mov   %[res], eax \n"
      : [res] "=r"(res)
      : [x] "r"(x)
      : "rax");
  return res;
}

int main() {
  int x = -3213;
  printf("%d %04x %d %04x\n", x, x, dividePor32Sinal(x), dividePor32Sinal(x));
  printf("%d %04x %d %04x\n", x, x, restoDaDividePor32(x), restoDaDividePor32(x));
  return 0;
}
/*
15: 0000 1111 -> ">>2" -> 0000 0011:3
15: 0000 1111
    0000 0011(mascara)
    ---------&
    0000 0011
*/