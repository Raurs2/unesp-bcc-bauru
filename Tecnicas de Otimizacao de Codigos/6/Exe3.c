#include <stdio.h>

unsigned char vet[] = {1, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 11, 1, 11, 1, 12, 1, 12, 1};
unsigned char n = 10;

int main() {
  int conta = 0;
  int contaMenores = 0;
  conta = &vet[19] - &vet[0] + 1;
  unsigned char *B;
  B = vet;
  do {
    if (*B < n)
      contaMenores++;
    B++;
    conta--;
  } while (conta > 0);
  printf("Contagem de menores que %d é %d\n", n, contaMenores);
  vet[20] = 123; // Cuidado com o indice, pois pode afetar outras variaveis
  printf("N = %d\n", n);
  printf("Enderecos: %ld, %ld, %ld\n", (long)&vet[19], (long)&vet[0], (long)&n);
  printf("Distancia entre o primeiro e último elemento: %ld\n", (long)(&vet[19] - &vet[0]));
  return 0;
}
