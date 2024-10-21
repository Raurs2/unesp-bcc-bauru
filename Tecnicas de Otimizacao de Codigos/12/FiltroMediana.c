#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LARG_IMG 2560
#define ALTU_IMG 1600

struct Pixel {
  unsigned char r, g, b;
};

struct Pixel imagem[ALTU_IMG][LARG_IMG];
struct Pixel imagemSai[ALTU_IMG][LARG_IMG];

char *leLinha(FILE *f) {
  static char str[1000];
  unsigned char c;
  int j = 0;

  c = fgetc(f);
  while (c == '#') {
    do {
      c = fgetc(f);
    } while (c != '\n');
    while (isspace(c = fgetc(f)))
      ;
  }

  do {
    str[j] = c;
    j++;
  } while (!isspace(c = fgetc(f)));

  str[j] = 0;
  return str;
}

void lePPM(char nomeArq[], struct Pixel img[ALTU_IMG][LARG_IMG]) {
  int larg, altu, cores, tam;
  char *p;
  FILE *f = fopen(nomeArq, "rb");
  if (!f) {
    printf("O arquivo da imagem não pode ser aberto para leitura.\n");
    exit(1);
  }
  if (strcmp(leLinha(f), "P6")) {
    printf("Não é um arquivo no formato PPM (P6) de imagem.\n");
    exit(1);
  }
  p = leLinha(f);
  larg = atoi(p);
  if (LARG_IMG != larg) {
    printf("A imagem apresenta largura %d, mas o valor desejado e' %d.\n", larg,
           LARG_IMG);
    exit(1);
  }
  p = leLinha(f);
  altu = atoi(p);
  if (ALTU_IMG != altu) {
    printf("A imagem apresenta altura %d, mas o valor desejado e' %d.\n", altu,
           ALTU_IMG);
    exit(1);
  };
  p = leLinha(f);
  cores = atoi(p);
  if (cores != 255) {
    printf("A imagem tem um valor máximo de %d, mas a valor de cor é de 255.\n",
           cores);
    exit(1);
  }
  tam = LARG_IMG * ALTU_IMG;
  if (fread(&img[0][0], 3, tam, f) != tam) {
    printf("O arquivo da imagem parace nao estar completo.\n");
    exit(1);
  }
  fclose(f);
}

void salvaPPM(char nomeArq[], struct Pixel img[ALTU_IMG][LARG_IMG]) {
  int tam;
  FILE *f = fopen(nomeArq, "wb");
  fprintf(f, "P6\n%d %d\n255\n", LARG_IMG, ALTU_IMG);
  tam = LARG_IMG * ALTU_IMG;
  if (fwrite(&img[0][0], 3, tam, f) != tam) {
    printf("O arquivo de imagem nao foi gravado corretamente.\n");
    exit(1);
  }
  fclose(f);
}

void testaTroca(int *v1, int *v2) {
  if (*v1 > *v2) {
    int t = *v1;
    *v1 = *v2;
    *v2 = t;
  }
}

void menor(int *v1, int *v2, int *v3) {
  if (*v1 > *v2) {
    *v1 = *v2;
  }
  if (*v1 > *v3) {
    *v1 = *v3;
  }
}

int mediana(int v1, int v2, int v3, int v4, int v5) {
  testaTroca(&v1, &v2);
  testaTroca(&v1, &v3);
  testaTroca(&v1, &v4);
  testaTroca(&v1, &v5);

  testaTroca(&v2, &v3);
  testaTroca(&v2, &v4);
  testaTroca(&v2, &v5);

  menor(&v3, &v4, &v5);

  return v3;
}

void processa(struct Pixel img[ALTU_IMG][LARG_IMG],
              struct Pixel imgSai[ALTU_IMG][LARG_IMG]) {
  int i, j;
  for (i = 1; i < ALTU_IMG - 1; i++) {
    for (j = 1; j < LARG_IMG - 1; j++) {
      imgSai[i][j].r = mediana(img[i - 1][j].r, img[i + 1][j].r, img[i][j].r,
                               img[i][j - 1].r, img[i][j + 1].r);
      imgSai[i][j].g = mediana(img[i - 1][j].g, img[i + 1][j].g, img[i][j].g,
                               img[i][j - 1].g, img[i][j + 1].g);
      imgSai[i][j].b = mediana(img[i - 1][j].b, img[i + 1][j].b, img[i][j].b,
                               img[i][j - 1].b, img[i][j + 1].b);
    }
  }
}

int main() {
  int j;
  clock_t inicio, final;
  double duracao;
  lePPM("LapisRuido.ppm", imagem);
  printf("Iniciando processamento:\n");
  inicio = clock();
  for (j = 0; j < 30; j++)
    processa(imagem, imagemSai);
  final = clock();
  duracao = (double)(final - inicio) / CLOCKS_PER_SEC;
  printf("Tempo utilizado no processamento = %f\n", duracao);
  salvaPPM("LapisSai.ppm", imagemSai);
  return 0;
}
