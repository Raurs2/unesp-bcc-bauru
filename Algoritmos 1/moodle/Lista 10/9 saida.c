#include <stdio.h>
typedef int matriz[3][3];
int main() {
matriz mat;
int i, j, inteiro, x, y, xant, yant, n;
inteiro = 1;
n = 3;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
mat[i][j] = 0;
x = (n + 1) / 2 - 1;
y = n - 1;
while (inteiro < 10) {
mat[x][y] = inteiro;
inteiro++;
xant = x;
yant = y;
x++;
y++;
if (x == n)
x = 0;
if (y == n)
y = 0;
if (mat[x][y] != 0) {
x = xant;
y = yant - 1;
}
}
for (i = 0; i < 3; i++) {
for (j = 0; j < 3; j++)
printf ("%2d ",mat[i][j]);
printf ("\n");
}
}