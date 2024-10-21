#include <string.h> 
#include <stdio.h> 
 
int main(){ 
 int soma = 0; 
 long int numero; 
 scanf("%ld", &numero); 
  
 while(numero > 0){ 
  int digito = numero % 10; 
  if(digito % 2 == 0){ 
   soma += digito; 
  } 
  numero /= 10; 
 } 
 printf("Os digitos pares somados resulta em: %d\n", soma); 
 return 0; 
}