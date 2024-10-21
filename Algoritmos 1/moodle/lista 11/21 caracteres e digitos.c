#include <stdio.h>
#include <string.h>
#include <ctype.h>

}
int main () {
  char texto[20], c = 0, i = 0, d = 0;
  printf ("Digite um texto: ");
  gets (texto);
  for ( i = 0; i < strlen(texto); i++)
  {
      if (isdigit(texto[i])) {
          c++;
      }
      if (!isdigit(texto[i]) && texto[i] != ' ') {
          d++;
      }
  }
  
  printf ("num %d\n", c);
  printf ("char %d\n", d);
  return 0;
}