#include<stdio.h>
#include<string.h>

int ehnumero (char t[]){
  int i;
  for (i=0; i<strlen(t); i++)	
    if (t[i]<'0' || t[i]>'9')
      return 0;
  return 1;	
}

int main() {
  char str[10];
  int num;
  do {
    printf ("Digite numero: ");
    gets(str);
  } while (!ehnumero(str));
  num = atoi(str)+10;
  printf ("Numero fornecido acrescido de 10 unidades: %d",num);
}  

