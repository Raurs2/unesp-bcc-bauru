#include <cstdio>
#include <cstring>

int impar(int x) {
  return x & 1;
}

int par(int x) {
  return (x & 1) ^ 1;
}

int main() {
  int x = 3425235;
  if (x & 1) {
    printf("é impar: %d\n", impar(x)); 
  }
  printf("%d %d\n", 10, impar(10));
  printf("%d %d\n", 11, impar(11));
  printf("%d %d\n", 12345676, impar(12345676));
  printf("%d %d\n", 12345673, impar(12345673));
  return 0;
}