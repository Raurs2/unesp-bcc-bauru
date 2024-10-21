#include <stdio.h>
#include <stdlib.h>
int a, b, c;
/*---------------------------------------*/
void P1 (int a) {
printf ("%d\n",a);
}
/*---------------------------------------*/
void P2 (int b) {
b = 2*b + 1;
P1(b);
}
/*---------------------------------------*/
void P3 (int b) {
b = 2*b + 1;
P1(b);
}
/*---------------------------------------*/
int P4 (int a, int b, int c) {
if (a > b && b > c) {
P3(a);
return (a+2);
}
if (a < b || c < b) {
P2(b);
return (2*b+c);
}
return 0;
}
/*---------------------------------------*/
int main () {
a = 3;
b = 4;
c = -1;
printf ("%d\n",P4(a,b,c));
P1(a);
P2(a);
P3(a);
printf ("%d\n",P4(a,b-c,c));
P2(b);
P3(b);
printf ("%d\n",P4(a+2,b,c+b-1));
P1(a);
P1(b);
P1(c);
}