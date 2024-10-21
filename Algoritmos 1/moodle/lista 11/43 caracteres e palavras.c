#include <stdio.h>
#include <string.h>
#include <ctype.h>

void mostraCaracteres (char texto[]) {
  int i, j, achou, cont, tot = 0;
  for (i = 0; i < strlen(texto); i++) {
    achou = 0;
    for (j = 0; j < i && !achou; j++)
      if (toupper(texto[i]) == toupper(texto[j])) achou = 1;
    if (!achou) {
      cont = 0;
      for (j = i; j < strlen(texto); j++)        
        if (toupper(texto[i]) == toupper(texto[j])){
            cont++;
        }
      printf ("%c - %d vez(es)\n",texto[i],cont);
      tot += cont;
    } 
  }
  printf("%d\n", tot);
}
int main () {
  char texto[50], c, i = 0;
  printf ("Digite um texto: ");
  gets (texto);
  mostraCaracteres (texto);
  
  c = strtok (texto," .,-");
        while (c != NULL) {
            i++;
            c = strtok(NULL," .,-");
        }
    printf("%d\n", i);
  printf ("\n\n");
  return 0;
}