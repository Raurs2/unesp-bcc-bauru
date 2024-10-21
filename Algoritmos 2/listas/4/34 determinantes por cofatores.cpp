#include <stdio.h>
#define ordem 4

void mostramatriz (int n, float m[][ordem]){
  int i, j;
  for (i = 0; i < n; i++){
  	for (j = 0; j < n; j++)
  	  printf ("%4.1f ",m[i][j]);
  	printf ("\n");
  }
}

void montaMatriz (int n, int i, float m[][ordem], float a[][ordem]){
  int cont, j, k;
  for (j = 1; j < n; j++){ // linha
    cont = 0;
    for (k = 0; k < n; k++) // coluna
      if (k != i) {
        a[j-1][cont] = m[j][k];
        cont++;
      }
  }
}

void montaMatriz2 (int n, int i, float m[][ordem], float a[][ordem]){
  int j, k;
  for (j = 1; j < n; j++){ 
    for (k = 0; k < i; k++) 
      a[j-1][k] = m[j][k];
    for (k = i+1; k < n; k++) 
      a[j-1][k-1] = m[j][k];    
  }
}
 
               
float determinante (int n, float m[][ordem]){
  if (n == 1)
    return m[0][0];
  float mat[ordem][ordem], s = 0;
  int sinal = 1, i;
  for (i = 0; i < n; i++){
    if (m[0][i] != 0){
      montaMatriz (n,i,m,mat);
      s += sinal*m[0][i]*determinante(n-1,mat);
    }
    sinal = -sinal;
  }
  return s;
}

int main (){
  float m[ordem][ordem] = {3, -1, 0, 1, 2, 2, 1, 1, 1, 0, 1, 2, 0, 1, 2, 2};
  //float m[ordem][ordem] = {1, 3, 5, 9, 1, 3, 1, 7, 4, 3, 9, 7, 5, 2, 0, 9};
  mostramatriz (ordem,m);
  printf ("%f",determinante(ordem,m));
}
