#include<stdio.h>
#define max 4
typedef int matriz[max][max];

int determinante(matriz mat,int n){
	matriz auxiliar; //matriz auxiliar;
	int i,j,k=0,sinal,det=0;
	if(n==1)
		return mat[0][0];
	while(k<n){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i!=0 && j!=k){
					if(j<k)
						auxiliar[i-1][j]=mat[i][j];
					else
						auxiliar[i-1][j-1]=mat[i][j];
				}
			}
		}
		if(k%2==0)
			sinal=1;
		else
			sinal=-1;
		det += mat[0][k]*sinal*determinante(auxiliar,n-1);
		k++;
	}
	return det;
}

void mostramatriz (int n, matriz m){
  int i, j;
  for (i = 0; i < n; i++){
  	for (j = 0; j < n; j++)
  	  printf ("%4d ",m[i][j]);
  	printf ("\n");
  }
}

void montaMat(matriz mat,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\n\nDigite A[%d][%d] = ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
}

int main(){
	int n;
	matriz m;
	printf("Digite a ordem da matriz quadrada: ");
	scanf("%d",&n);
	montaMat (m,n);
	mostramatriz (n,m);
	printf("\n\nDeterminante da matriz digitada: %d",determinante(m,n));
	return 0;
}
