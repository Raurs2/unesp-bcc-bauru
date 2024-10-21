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

struct PixelHSI {
  unsigned char h, s, i;
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

#define PRETO 0, 0, 0
#define CINZA 128, 128, 128, 50

#define AZUL_CLARO 0, 210, 250
#define DIST_AZUL_CLARO 180

#define AZUL 0, 40, 140
#define DIST_AZUL 80

#define VERDE_CLARO 100, 180, 0
#define DIST_VERDE_CLARO 60

#define VERDE 0, 110, 0
#define DIST_VERDE 90

#define LARANJA 230, 100, 0
#define DIST_LARANJA 30

#define AMARELO 240, 190, 0
#define DIST_AMARELO 40

#define COR1 AZUL_CLARO
#define DIST_COR1 DIST_AZUL_CLARO

#define SATURA(x) x > 255 ? 255 : (x < 0 ? 0 : x);

void processa(struct Pixel img[ALTU_IMG][LARG_IMG],
              struct Pixel imgSai[ALTU_IMG][LARG_IMG]) {
  struct Pixel corEtiqueta = {COR1};
  struct Pixel pixelPreto = {PRETO};
  int i, j;
  for (i = 0; i < ALTU_IMG; i++) {
    for (j = 0; j < LARG_IMG; j += 3) {
      struct Pixel pixelAtual = img[i][j];
      int dr = corEtiqueta.r - pixelAtual.r;
      int dg = corEtiqueta.g - pixelAtual.g;
      int db = corEtiqueta.b - pixelAtual.b;
      if (dr * dr + dg * dg + db * db < DIST_COR1 * DIST_COR1) {
        pixelAtual.r = SATURA(pixelAtual.r * 1.2);
        pixelAtual.g = SATURA(pixelAtual.g * 1.2);
        pixelAtual.b = SATURA(pixelAtual.b * 1.2);
        imgSai[i][j] = pixelAtual;
      } else {
        pixelAtual.r = SATURA(pixelAtual.r * 0.3);
        pixelAtual.g = SATURA(pixelAtual.g * 0.3);
        pixelAtual.b = SATURA(pixelAtual.b * 0.3);
        imgSai[i][j] = pixelAtual;
      }

      pixelAtual = img[i][j+1];
      dr = corEtiqueta.r - pixelAtual.r;
      dg = corEtiqueta.g - pixelAtual.g;
      db = corEtiqueta.b - pixelAtual.b;
      if (dr * dr + dg * dg + db * db < DIST_COR1 * DIST_COR1) {
        pixelAtual.r = SATURA(pixelAtual.r * 1.2);
        pixelAtual.g = SATURA(pixelAtual.g * 1.2);
        pixelAtual.b = SATURA(pixelAtual.b * 1.2);
        imgSai[i][j+1] = pixelAtual;
      } else {
        pixelAtual.r = SATURA(pixelAtual.r * 0.3);
        pixelAtual.g = SATURA(pixelAtual.g * 0.3);
        pixelAtual.b = SATURA(pixelAtual.b * 0.3);
        imgSai[i][j+1] = pixelAtual;
      }

      pixelAtual = img[i][j+2];
      dr = corEtiqueta.r - pixelAtual.r;
      dg = corEtiqueta.g - pixelAtual.g;
      db = corEtiqueta.b - pixelAtual.b;
      if (dr * dr + dg * dg + db * db < DIST_COR1 * DIST_COR1) {
        pixelAtual.r = SATURA(pixelAtual.r * 1.2);
        pixelAtual.g = SATURA(pixelAtual.g * 1.2);
        pixelAtual.b = SATURA(pixelAtual.b * 1.2);
        imgSai[i][j+2] = pixelAtual;
      } else {
        pixelAtual.r = SATURA(pixelAtual.r * 0.3);
        pixelAtual.g = SATURA(pixelAtual.g * 0.3);
        pixelAtual.b = SATURA(pixelAtual.b * 0.3);
        imgSai[i][j+2] = pixelAtual;
      }

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
  for (j = 0; j < 120; j++)
    processa(imagem, imagemSai);
  final = clock();
  duracao = (double)(final - inicio) / CLOCKS_PER_SEC;
  printf("Tempo utilizado no processamento = %f\n", duracao);
  salvaPPM("LapisSai.ppm", imagemSai);
  return 0;
}
