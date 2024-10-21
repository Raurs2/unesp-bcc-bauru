// Escreva uma fun��o que receba uma string e imprima uma tabela com o n�mero de 
// ocorr�ncias de cada caractere na string. Escreva um programa para testar a fun��o.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void mostraCaracteres (char texto[]) {
  int i, j, achou, cont;
  for (i = 0; i < strlen(texto); i++) {
    achou = 0;
    for (j = 0; j < i && !achou; j++)
      if (toupper(texto[i]) == toupper(texto[j])) achou = 1;
    if (!achou) {
      cont = 0;
      for (j = i; j < strlen(texto); j++)        
        if (toupper(texto[i]) == toupper(texto[j])) cont++;
      printf ("%c - %d vez(es)\n",texto[i],cont);
    }  
  }
}
int main () {
  char texto[20];
  printf ("Digite um texto: ");
  gets (texto);
  mostraCaracteres (texto);
  printf ("\n\n");
  return 0;
}

