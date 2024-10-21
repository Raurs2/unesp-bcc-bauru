#include <string.h> 
#include <stdio.h> 
 
int main(){ 
 int soma = 0; 
 char numero[100]; 
 scanf("%s", numero); 
 int tamanho = strlen(numero); 
 for(int i = 0; i < tamanho; i++){ 
  int digito = numero[i] - '0'; 
  if(digito % 2 == 0){ 
   soma += digito; 
  } 
 } 
 printf("Os digitos pares somados resulta em: %d\n", soma); 
 return 0; 
}