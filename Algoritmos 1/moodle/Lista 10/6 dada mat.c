#include <stdio.h>
#include <conio.h>
typedef char matriz[4][4];
int main () {
int i, j;
char aux;
matriz mat;
for (i = 0; i < 4; i++)
for (j = 0; j < 4; j++)
mat[i][j] = getche();
/* Suponha que a matriz acima seja a matriz lida */
for (i = 0; i < 4; i++)
for (j = i+1; j < 4; j++) {
aux = mat[i][j];
mat[i][j] = mat[j][i];
mat[j][i] = aux;
}
aux = mat[0][0];
mat[0][0] = mat[3][3];
mat[3][3] = aux;
aux = mat[1][1];
mat[1][1] = mat[2][2];
mat[2][2] = aux;
for (i = 0; i < 4; i++) {
for (j = 0; j < 4; j++)
printf ("%c ",mat[i][j]);
printf ("\n");
}
}