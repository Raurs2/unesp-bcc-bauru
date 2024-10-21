#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main (){
  int col, lin = 13, n;
  char texto[] = "Calculadora";
  n = strlen(texto);
  col = (80 - n) / 2;
  // cálculo da centralização do título na linha
  gotoxy (col,lin);
  printf ("%s", texto);
  gotoxy (4,2);
  printf ("Acabou!");
}
