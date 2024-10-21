// Programa 1
#include <stdio.h>
#define max 2
typedef int vet[max];
typedef int mat[max][max];
int main() {
vet a;
mat b;
int i, j, soma1, soma2;
for (i = 0; i < max; i++) {
printf ("a[%d] = ",i+1);
scanf ("%d",&a[i]);
}
for (i = 0; i < max; i++)
for (j = 0; j < max; j++) {
printf ("b[%d][%d] = ",i+1,j+1);
scanf ("%d",&b[i][j]);
}
soma1 = soma2 = 0;
for (i = 0; i < max; i++)
for (j = 0; j < max; j++) {
soma1 += a[i];
soma2 += b[i][j];
}
printf ("%d %d",soma1,soma2);
}