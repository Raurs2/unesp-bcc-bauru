// Faça um programa que leia cinco cadeias de caracteres e as exibe no monitor.

#include <stdio.h>
int main () {
  char texto[5][20];
  int i;
  for (i = 0; i < 5; i++) {
    printf ("\nDigite uma cadeia de caracteres: ");
    gets (texto[i]);
  }
  printf ("\n\nAs cadeias de caracteres digitadas foram:\n");
  for (i = 0; i < 5; i++)
    printf ("%s\n",texto[i]);
}

