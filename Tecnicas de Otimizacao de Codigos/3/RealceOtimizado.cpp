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

int matHue[201];
void criaMatHue() {
for (int i = 0; i <= 200; i++) {
matHue[i] = round(acos((i - 100) / 100.0) * 180 / M_PI);
}
}

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

int calculaHueAPartirDoRGB(struct Pixel cor) {
  float r = cor.r;
  float g = cor.g;
  float b = cor.b;
  float numerador = r - (g + b) / 2.0;
  float denominador = sqrt(r * r + g * g + b * b - r * g - r * b + g * b);
  int hue;
if (denominador != 0) {
int indice = numerador * 100 / denominador + 100;
hue = matHue[indice];
} else {
hue = 0;
}
  if (b > g) {
    hue = 360 - hue;
  }
  return hue;
}

int calculaDistanciaAngulos(int ang1, int ang2) {
  int dist = ang1 - ang2;
  if (abs(dist) > 180) {
    if (ang1 < ang2) {
      dist = 360 + dist;
    } else {
      dist -= 360;
    }
  }
  return dist;
}

int saturaDe0A255(int v) {
  if (v < 0) {
    return 0;
  } else if (v > 255) {
    return 255;
  } else {
    return v;
  }
}

void realcaCor(struct Pixel *cor) {
  cor->r = saturaDe0A255(cor->r * 1.2);
  cor->g = saturaDe0A255(cor->g * 1.2);
  cor->b = saturaDe0A255(cor->b * 1.2);
}

void transformaEmNiveisDeCinza(struct Pixel *cor) {
  int nivel = cor->r * 0.30 + cor->g * 0.59 + cor->b * 0.11;
  cor->r = cor->g = cor->b = nivel;
}

#define AZUL 240

void processa(struct Pixel img[ALTU_IMG][LARG_IMG],
              struct Pixel imgSai[ALTU_IMG][LARG_IMG]) {
  int i, j;
  for (i = 0; i < ALTU_IMG; i++) {
    for (j = 0; j < LARG_IMG; j += 1) {
      struct Pixel pixelAtual = img[i][j];
      // float distancia = calculaDistancia(pixelAtual, corDesejada);
      int hue = calculaHueAPartirDoRGB(pixelAtual);
      int distancia = abs(calculaDistanciaAngulos(hue, AZUL));
      if (distancia > 30) {
        transformaEmNiveisDeCinza(&pixelAtual);
      } else {
        realcaCor(&pixelAtual);
      }
      imgSai[i][j] = pixelAtual;
    }
  }
}

int main() {
  int j;
  clock_t inicio, final;
  double duracao;
  criaMatHue();
  lePPm("Lapis.ppm", imagem);
  printf("Iniciando processamento:\n");
  inicio = clock();
  for (j = 0; j < 10; j++)
    processa(imagem, imagemSai);
  final = clock();
  duracao = (double)(final - inicio) / CLOCKS_PER_SEC;
  printf("Tempo utilizado no processamento = %f\n", duracao);
  salvaPPM("LapisSai.ppm", imagemSai);
  return 0;
}
