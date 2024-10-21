#include<stdio.h>
  short int v[1000];
  int main()  {
  asm(    // atribui o endereço de v para rbx
          "  lea rbx, %[v]		  \n" 
          // atribui 1234 para ax
          "  mov ax, 0		    \n"
          // inicia contador 
          "  mov cx, 10       \n"
          "repete:              \n"
          // soma o valor da posicao do vetor no ax
          "  add ax, word ptr [rbx]	  \n"
          // incrementa o ponteiro para o próximo elemento do vetor
          "  add rbx, 2         \n"
          // decrementa o contador
          "  dec cx             \n"
          // volta para "repete" enquanto cx > 0
          "  jnz repete         \n"
          : [v] "=m"(v)
          :
          : "ax", "cx", "rbx");
  return 0;
}
