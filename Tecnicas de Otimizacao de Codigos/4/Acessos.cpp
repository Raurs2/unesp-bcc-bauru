#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int contA;

int contaLetra(FILE *pArq, char c) {
  int cont = 0;
  while (!feof(pArq)) {
    if (fgetc(pArq) == 'a') {
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
  for (j = 0; j < 20; j++) {
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
