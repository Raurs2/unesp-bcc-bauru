#include <stdio.h>
typedef int matriz1[3][4];
typedef char matriz2[2][2];
int main () {
matriz1 m;
matriz2 n;
int i, j = 1;
for (i = 0; i < 3; i++) {
m[i][j] = m[i][j+2] = 2;
m[i][j-1] = m[i][j+1] = 1;
}
for (i = 0; i < 2; i++)
for (j = 0; j < 2; j++)
if (i == j)
n[i][j] = 'a';
else
n[i][j] = 'z';
for (i = 0; i < 3; i++)
for (j = 0; j < 4; j++)
printf ("m[%d][%d] = %2d\n",i,j,m[i][j]);
printf ("\n");
for (i = 0; i < 2; i++)
for (j = 0; j < 2; j++)
printf ("n[%d][%d] = %2c\n",i,j,n[i][j]);
}