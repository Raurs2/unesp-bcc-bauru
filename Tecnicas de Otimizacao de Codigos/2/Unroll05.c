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

void lePPm(char nomeArq[], struct Pixel img[ALTU_IMG][LARG_IMG]) {
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

void processa(struct Pixel img[ALTU_IMG][LARG_IMG], struct Pixel imgSai[ALTU_IMG][LARG_IMG]) {
  int i, j;
  for (i = 0; i < ALTU_IMG; i++) {
    struct Pixel a, b, c, d, e, f, g, h, x;
    for (j = 0; j < LARG_IMG; j += 16) {

      a = img[i][j];
      x = img[i][j + 1];
      a.r = (a.r + x.r) / 2;
      a.g = (a.g + x.g) / 2;
      a.b = (a.b + x.b) / 2;

      b = img[i][j + 2];
      x = img[i][j + 3];
      b.r = (b.r + x.r) / 2;
      b.g = (b.g + x.g) / 2;
      b.b = (b.b + x.b) / 2;

      c = img[i][j + 4];
      x = img[i][j + 5];
      c.r = (c.r + x.r) / 2;
      c.g = (c.g + x.g) / 2;
      c.b = (c.b + x.b) / 2;

      d = img[i][j + 6];
      x = img[i][j + 7];
      d.r = (d.r + x.r) / 2;
      d.g = (d.g + x.g) / 2;
      d.b = (d.b + x.b) / 2;

      e = img[i][j + 8];
      x = img[i][j + 9];
      e.r = (e.r + x.r) / 2;
      e.g = (e.g + x.g) / 2;
      e.b = (e.b + x.b) / 2;

      f = img[i][j + 10];
      x = img[i][j + 11];
      f.r = (f.r + x.r) / 2;
      f.g = (f.g + x.g) / 2;
      f.b = (f.b + x.b) / 2;

      g = img[i][j + 12];
      x = img[i][j + 13];
      g.r = (g.r + x.r) / 2;
      g.g = (g.g + x.g) / 2;
      g.b = (g.b + x.b) / 2;

      h = img[i][j + 14];
      x = img[i][j + 15];
      h.r = (h.r + x.r) / 2;
      h.g = (h.g + x.g) / 2;
      h.b = (h.b + x.b) / 2;

      imgSai[i][j / 2] = a;
      imgSai[i][(j + 2) / 2] = b;
      imgSai[i][(j + 4) / 2] = c;
      imgSai[i][(j + 6) / 2] = d;
      imgSai[i][(j + 8) / 2] = e;
      imgSai[i][(j + 10) / 2] = f;
      imgSai[i][(j + 12) / 2] = g;
      imgSai[i][(j + 14) / 2] = h;
    }
  }
}

int main() {
  int j;
  clock_t inicio, final;
  double duracao;
  lePPm("Lapis.ppm", imagem);
  printf("Iniciando processamento:\n");
  inicio = clock();
  for (j = 0; j < 300; j++)
    processa(imagem, imagemSai);
  final = clock();
  duracao = (double)(final - inicio) / CLOCKS_PER_SEC;
  printf("Tempo utilizado no processamento = %f\n", duracao);
  salvaPPM("LapisSai.ppm", imagemSai);
  return 0;
}