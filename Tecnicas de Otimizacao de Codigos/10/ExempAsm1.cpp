#include <cstdio>
int vGlobal[] = {1, 2, 3};
int v[] = {4, 5, 6}; // passado na chamada de func1

int func1(int vParam[]) {
  int vLocal[] = {7, 8, 9};
  int retorno;
  asm(
      // nos vetores locais e globais, 
      // usa-se LEA para carregar o endereço
      "   lea   RBX, %[vLocal]  \n"
      "   lea   RDI, %[vGlobal] \n"
      // nos vetores em parâmetros, 
      // usa-se MOV para carregar o endereço
      "   mov   RDX, %[vParam]  \n"
      // EAX = vLocal[0]+vGlobal[0]+vParam[0]
      "   mov   RCX, 0          \n"
      "   mov   EAX, [RBX]      \n"
      "   add   EAX, [RDI+RCX]  \n"
      "   add   EAX, [RDX+0]    \n"
      // EAX += vLocal[1]+vGlobal[1]+vParam[1]
      "   mov   RCX, 4          \n"
      "   add   EAX, [RBX+4]    \n"
      "   add   EAX, 4[RDI]  \n"
      "   add   EAX, [RDX+RCX]  \n"
      // EAX += vLocal[2]+vGlobal[2]+vParam[2]
      "   add   EAX, [RBX+8]    \n"
      "   add   EAX, [RDI+RCX+4]\n"
      "   add   EAX, 4[RDX+RCX] \n"
      "   mov   %[retorno], eax \n"
      : [retorno] "=g"(retorno)
      : [vGlobal]  "m"(vGlobal), 
        [vLocal]   "m"(vLocal), 
        [vParam]   "m"(vParam)
      : "rax", "rbx", "rcx", "rdx", "rdi");
  return retorno;
}

int main() {
  int var = func1(v);
  printf("%d\n", var);
  return 0;
}
