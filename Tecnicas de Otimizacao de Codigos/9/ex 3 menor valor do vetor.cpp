#include <stdio.h>
int main() {
  short int vetor[1000] = {2,4,5,6,8,24,12,4,2,-7,123,-12,13,4,75,-17,-3,9,6,1};
  short int menor=32766,i;
  for(i=20;i<1000;i++)
    vetor[i]=0;
  asm(" push ax \n"
    " push cx \n"
    " push rbx \n"
    " LEA RBX,%[vetor] \n"
    " MOV CX, 1000 \n"
    " MOV AX, %[menor] \n"
    " procura: \n"
    " CMP AX,WORD PTR [RBX] \n"
    " JLE menor \n"
    " MOV AX,WORD PTR [RBX] \n"
    " menor: \n"
    " ADD RBX, 2 \n"
    " DEC CX \n"
    " JNZ procura \n"
    " MOV %[menor], AX \n"
    " pop rbx \n"
    " pop cx \n"
    " pop ax \n"
    : [menor] "+r"(menor),[vetor] "=m"(vetor)
    : "ax","cx","rbx");
  printf("%d\n", menor);
  return 0;
}