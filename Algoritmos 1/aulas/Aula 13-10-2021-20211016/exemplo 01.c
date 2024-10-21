#include<stdio.h>
#include<string.h>
int main() {
  char str[50], ch;
  strcpy(str,"Procura uma letra inicial de caracteres");
  ch='l';
  printf("%d\n\n",-(str-strchr(str,ch)));
  return 0;
}

