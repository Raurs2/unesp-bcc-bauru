#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define LARG_IMG 2560
#define ALTU_IMG 1600

struct Pixel {
  unsigned char r, g, b;
};

Pixel imagem[ALTU_IMG][LARG_IMG];
Pixel imagemSai[ALTU_IMG][LARG_IMG];

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

void lePPm(char nomeArq[], Pixel img[ALTU_IMG][LARG_IMG]) {
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
  for (int i = 0; i < ALTU_IMG; i++) {
    for (int j = 0; j < LARG_IMG; j++) {
      if (fread(&img[i][j], 3, 1, f) != 1) {
        printf("O arquivo da imagem parace nao estar completo.\n");
        exit(1);
      }
    }
  }
  fclose(f);
}

void ligaBit(char &c, int nBit) { c |= 1 << nBit; }

void desligaBit(char &c, int nBit) { c &= ~(1 << nBit); }

bool LSBPixelEstahLigado(Pixel p, char canal) {
  switch (canal) {
  case 'R':
    return (p.r & 1) != 0;
    break;
  case 'G':
    return (p.g & 1) != 0;
    break;
  case 'B':
    return (p.b & 1) != 0;
  }
  return false;
}

void processa(Pixel img[ALTU_IMG][LARG_IMG], char canal) {
  char letra;
  int posBit;
  char nomeArq[200];
  int indLetra = 0;

  for (int j = 0; j < LARG_IMG; j++) {
    posBit = j % 8;
    if (posBit == 0) {
      letra = 0;
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x01;
      }
    } else if (posBit == 1) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x02;
      }
    } else if (posBit == 2) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x04;
      }
    } else if (posBit == 3) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x08;
      }
    } else if (posBit == 4) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x10;
      }
    } else if (posBit == 5) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x20;
      }
    } else if (posBit == 6) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x40;
      }
    } else if (posBit == 7) {
      if (LSBPixelEstahLigado(img[0][j], canal)) {
        letra |= 0x80;
      }
      nomeArq[indLetra++] = letra;
      if (letra == '\0')
        break;
    }
  }
  FILE *fp = fopen(nomeArq, "wb");
  for (int i = 1; i < ALTU_IMG; i++) {
    for (int j = 0; j < LARG_IMG; j++) {
      posBit = j % 8;
      if (posBit == 0) {
        letra = 0;
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x01;
        }
      } else if (posBit == 1) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x02;
        }
      } else if (posBit == 2) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x04;
        }
      } else if (posBit == 3) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x08;
        }
      } else if (posBit == 4) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x10;
        }
      } else if (posBit == 5) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x20;
        }
      } else if (posBit == 6) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x40;
        }
      } else if (posBit == 7) {
        if (LSBPixelEstahLigado(img[i][j], canal)) {
          letra |= 0x80;
        }
        if (letra == '\0') {
          i = ALTU_IMG;
          break;
        }
        fputc(letra, fp);
      }
    }
  }
  fclose(fp);
}

int main() {
  int j;
  clock_t inicio, final;
  double duracao;
  printf("Iniciando processamento:\n");
  inicio = clock();
  for (j = 0; j < 10; j++) {
    lePPm("LapisComTexto.ppm", imagem);
    processa(imagem, 'R');
    processa(imagem, 'G');
    processa(imagem, 'B');
  }
  final = clock();
  duracao = (double)(final - inicio) / CLOCKS_PER_SEC;
  printf("Tempo utilizado no processamento = %f\n", duracao);
  return 0;
}
