#include <stdio.h>
int main() {
char aux, vet[11] = {'T','R','X','S',' ','E','O','B','A','!','\0'};
int i;
aux = vet[5];
vet[5] = vet[8];
vet[8] = aux;
for (i = 0; i < 4; i++) {
aux = vet[i];
vet[i] = vet[8-i-1];
vet[8-i-1] = aux;
}
vet[5] = vet[1];
for (i = 0; i < 10; i++)
printf ("%c",vet[i]);
}
// BOA SORTE!