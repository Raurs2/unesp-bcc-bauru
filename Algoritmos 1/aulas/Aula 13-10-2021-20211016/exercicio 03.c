// Faça um programa que conte o número de vogais de um texto fornecido pelo usuário.

#include <stdio.h>
#include <stdlib.h>
int contaVogais(char s[]) {
  int i, j, numVogais = 0;
  char vogais[] = "aeiouAEIOU";
  for (i = 0; s[i] != '\0'; ++i) {   // for (i=0; i<strlen(s); i++)
    for (j = 0; vogais[j] != '\0'; ++j) // for (j=0; j<strlen(vogais); j++)
     if (vogais[j] == s[i]) {
       numVogais += 1;
       break;
     }
  }
  return numVogais;
}
int main () {
  char texto[20];
  gets (texto);
  printf ("\n\nNumero de vogais no texto \"%s\": %d.\n",texto,contaVogais(texto));
  system ("pause");
}

