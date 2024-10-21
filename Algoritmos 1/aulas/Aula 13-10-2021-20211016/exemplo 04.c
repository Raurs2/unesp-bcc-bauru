#include <stdio.h>
#include <string.h>
int main() {
  char t1[] = "linguagem de desenvolvimento C";
  char t2[] = "de", *texto;
  texto = strstr(t1, t2);
  if (texto != NULL)
    printf("\"""%s\""" esta na string.", texto);
  else
  puts("A substring nao foi localizada.");
}

