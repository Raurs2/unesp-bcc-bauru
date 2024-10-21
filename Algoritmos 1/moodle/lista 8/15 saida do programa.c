#include <stdio.h>
int x, y;
/*---------------------------------------*/
void A() {
printf ("Passou pelo A.\n");
}
/*---------------------------------------*/
void B (int x) {
printf ("Passou pelo B com x = %d.\n",x);
}
/*---------------------------------------*/
void C (int y) {
printf ("Passou pelo C com valor de y igual a %d.\n",y);
y = 1;
B(y);
}
/*---------------------------------------*/
int D (int r, int s) {
r += s++;
if (r > s+10)
return r;
return s;
}
/*---------------------------------------*/
int main () {
x = 15;
y = 10;
A();
B(3);
x = D(x,y);
printf("Valor da funcao D: %d - x = %d e y = %d.\n",D(x-y,x+1),x,y);
C(x);
C(y+5);
}