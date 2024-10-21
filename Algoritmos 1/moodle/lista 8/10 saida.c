#include <stdio.h>
int x, y;
/*---------------------------------------*/
void A () {
printf ("Passou pelo A.\n");
}
/*---------------------------------------*/
void B (int x) {
printf ("Passou em B com valor %d.\n",x);
}
/*---------------------------------------*/
void C (int y) {
printf ("Valor de y: %d\n",y);
y = 1;
B(y);
}
/*---------------------------------------*/
int D (int r, int s) {
if (r > s) return x;
else return y;
}
/*---------------------------------------*/
int main () {
x = 20;
y = 30;
B(3);
B(4);
A();
x = D(D(7,2),3);
printf ("Valor de x: %d\n",x);
C(x);
C(x-3);
C(y);
A ();
}