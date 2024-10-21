#include <stdio.h>
typedef int matriz[3][2];
int main () {
int i, j;
matriz m;
m[0][0] = 1;
m[0][1] = 2;
m[1][0] = 3;
m[1][1] = 4;
m[2][0] = 5;
m[2][1] = 6;
for (i = 0; i < 3; i++) {
for (j = 0; j < 2; j++)
printf ("%2d ",m[i][j]);
printf ("\n");
}
printf ("\n");
for (i = 0; i < 2; i++) {
for (j = 0; j < 3; j++)
printf ("%2d ",m[j][i]);
printf ("\n");
}
}