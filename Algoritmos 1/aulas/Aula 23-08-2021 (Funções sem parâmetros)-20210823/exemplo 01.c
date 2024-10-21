#include <stdio.h>
void mensagem (void) {
  printf ("\nSou uma funcao!\n");
}
/*-------------------------------------------------*/
void mensagem1 () {
  printf ("\nSou uma outra funcao!\n");
}
/*-------------------------------------------------*/
void tracos () {
  int i;  // variavel local a funcao tracos
  printf ("\n");  
  for (i = 1; i <= 40; i++)
    printf ("-");
  printf ("\n");  
}
/*-------------------------------------------------*/
int main() {
  int i = 10;	
  mensagem ();
  tracos ();
  printf ("Variavel i da funcao main: %d",i);
  mensagem1 ();
  tracos();
  tracos();
  tracos();
 }

