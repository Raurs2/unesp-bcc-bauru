#include <cstdio>
#include <cstring>

int main() {
  char linha[] = "abc+defg-hi*jkl";
  char *palavra;
  palavra = strtok(linha, "+*-");
  while (palavra != NULL) {
    printf("%lu %s\n", strlen(palavra), palavra);
    palavra = strtok(NULL, "-*+");
  }
  return 0;
}