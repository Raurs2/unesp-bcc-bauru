#include <cstdio>
#include <cstring>

int dividePor2(int x) {
  return x >> 1;
}

int multiplicaPor8(int x) {
  return x << 3;
}

int main() {
  int x = -12;
  printf("%d %04x %d %04x\n", x, x, dividePor2(x), dividePor2(x));
  printf("%d %04x %d %04x\n", x, x, multiplicaPor8(x), multiplicaPor8(x));
  return 0;
}
/*
12: 0000 1100 -> ">>1" -> 0000 0110:6 -> ">>1" -> 0000 0011:3
12: 0000 1100 -> "<<3" -> 0110 0000:96
-12:
244:
*/