#include <cstdio>
#include <cstring>

void convMaiusculas1(char str[]) {
  int tam = strlen(str);
  for (int i = 0; i < tam; i++) {
    str[i] = str[i] & 0b11011111;
  }
}

void convMaiusculas2(char str[]) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = str[i] & (~0b00100000);
  }
}

void convMaiusculas3(char str[]) {
  while (*str != '\0') {
    *str = *str & (~0b00100000);
    str++;
  }
}

void convMaiusculas4(char str[]) {
  while (*str != '\0') {
    *str &= (~0b00100000);
    str++;
  }
}

void convMaiusculas(char str[]) {
  asm("    mov   rbx,  %[str]   \n"
      "repete%=:                \n"
      "    mov   al, [rbx]      \n"
      "    or    al, al         \n"
      "    jz    fim%=          \n"
      "    and   al, 0b11011111 \n"
      "    mov   [rbx], al      \n"
      "    inc   rbx            \n"
      "    jmp   repete%=       \n"
      "fim%=:                   \n"
      :
      : [str] "m"(str)
      : "rax", "rbx");
}

int main() {
  char str[] = "tesTE";
  convMaiusculas(str);
  printf("%s\n", str);
  return 0;
}
/*
1: 0000 0001:0x01
2: 0000 0010:0x02
4: 0000 0100:0x04
8: 0000 1000:0x08
16:0001 0000:0x10
32:0010 0000:0x20

0100 1011
0100 1011
---------or
0100 1011
Z indica se deu zero!!!
*/