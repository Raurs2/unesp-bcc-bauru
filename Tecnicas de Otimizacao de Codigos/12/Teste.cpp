#include <cstdio>

#define SQR(x) (x) * (x)

#define IMPRIME_MAX(i, j)                                                      \
  if (i > j) {                                                                 \
    printf("%d\n", i);                                                         \
  } else {                                                                     \
    printf("%d\n", j);                                                         \
  }

#define TEXTO(txt) "asdas " #txt \
" zzzz "\
" 1111 "

#define IMPRIME(Xis) printf("Imprime " #Xis ": %d\n", Xis);

int main() {
  int aaaa = 12;
  int A = 10, B = 20;
  IMPRIME_MAX(A, 5)
  IMPRIME(B);
  IMPRIME(123);
  printf("aaa"
  "bbb" 
  "bbb" 
  "ddd\n");
  printf("%d\n", SQR(aaaa + 1));
  printf(TEXTO($$$$));
  return 0;
}
