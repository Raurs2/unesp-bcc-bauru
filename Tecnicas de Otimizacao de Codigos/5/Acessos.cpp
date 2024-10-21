#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * tamanho medido do arquivo em bytes:
 * 4055830
 */
const int MAX_CARACTERES_NA_BIBLIA = 4055831;
const int MAX_CARACTERES_POR_LINHA = 1000;

char tudo[MAX_CARACTERES_NA_BIBLIA + 1];
int contA;

int contaLetra(FILE *pArq, char c) {
  int cont = 0;
  while (!feof(pArq)) {
    if (fgetc(pArq) == c) {
      cont++;
    }
  }
  return cont;
}

char letraAContar = 'a';

int main() {
  int j;
  clock_t inicio, final;
  double duracao;
  inicio = clock();
  for (j = 0; j < 100; j++) {
    contA = 0;
    FILE *pArq = fopen("biblia-em-txt.txt", "rt");
    contA = contaLetra(pArq, letraAContar);
    fclose(pArq);
  }
  final = clock();
  printf("Foram encontradas %d ocorrências da letra \'%c\'\n", contA, letraAContar);
  duracao = (double)(final - inicio) / CLOCKS_PER_SEC;
  printf("Tempo utilizado no processamento = %f\n", duracao);
}
