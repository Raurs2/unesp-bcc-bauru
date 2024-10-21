#include <stdio.h>
#include <windows.h>
int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
int main () {
  int i;
  for (i = 0; i <= 127; i++) {
    SetColor (i);
    printf (" Cor %d ",i);
  }  
}
