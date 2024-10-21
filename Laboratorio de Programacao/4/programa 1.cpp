#include <string.h> 
#include <stdio.h> 
 
char transformaParaMaiuscula(char c){ 
 if('a' <= c && c <= 'z'){ 
  c -= 32; 
 } 
 return c; 
} 
 
void analisa(char c){ 
 c = transformaParaMaiuscula(c); 
 if('A' <= c && c <= 'Z'){ 
  printf("Caractere %c: %dª letra do alfabeto!\n", c, c-'A'+1); 
 } else{ 
  int digito = c - '0'; 
  printf("Digito %d; e %s\n", digito,  
  digito%2 == 0 ? "par" : "impar"); 
 } 
} 
 
int main(){ 
 char str[100]; 
 strcpy(str, "ABcdXyZ129"); 
 int tamanho = strlen(str); 
 for(int i = 0; i < tamanho; i++){ 
  analisa(str[i]); 
 } 
 for(char c = 'i'; c <= 'r'; c++){ 
  printf("Caractere %c = decimal %d = hexadecimal %x\n", c, c, c); 
 } 
  
 return 0; 
}