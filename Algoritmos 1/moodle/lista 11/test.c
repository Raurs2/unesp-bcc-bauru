#include<stdio.h>
#include<string.h>
int main() {
char str[50], ch;
strcpy(str,"Procura uma letra inicial de caracteres");
ch='l';
printf("%s\n\n",strchr(str,ch));
}