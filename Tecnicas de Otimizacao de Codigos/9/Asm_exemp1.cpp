#include<stdio.h>
  short int v[1000];
  int main()  {
  asm(    // atribui o endereço de v para rbx
          "  lea rbx, %[v]		  \n" 
          // atribui 1234 para ax
          "  mov ax, 1234		    \n"
          // inicia contador 
          "  mov cx, 1000       \n"
          "repete:              \n"
          // atribui o valor de ax para o endereço em rbx
          "  mov word ptr [rbx], ax	  \n"
          // incrementa o poteiro para o próximo elemento do vetor
          "  add rbx, 2         \n"
          // decrementa o contador
          "  dec cx             \n"
          // volta para "repete" enquanto cx > 0
          "  jnz repete         \n"
          : [v] "=m"(v)
          :
          : "ax", "cx", "rbx");
  printf("%d %d %d\n", v[997], v[998], v[999]);
  return 0;
}
