#include <bits/stdc++.h>
#define max 15

int funcao(int vetor[max], int atual) {
	if(vetor[atual]) {
		vetor[atual] = 0;
		if(vetor[atual+1] || vetor[atual+2]) {
			return 1+funcao(vetor,atual+1)+funcao(vetor,atual+2);
		} else {
			return 1;
		}
	}
	return 0;
}

int main() {
	int t, i, n, k,j,x;
	int infect[max];
	int maior, menor, atual;
	
	scanf("%d", &t);
	
	for(i = 0; i<t; i++) {
		scanf("%d", &n);
		
		for(k = 0; k<max; k++) {
			infect[k] = 0;
		}
		
		maior = 0;
		menor = 100;
		atual = 0;
	
		for(j = 0; j<n; j++) {
			scanf("%d", &x);
			infect[x] = 1;
		}
		
		for(k=0; k<max; k++) {
			atual = funcao(infect,k);
			if(atual>maior) maior = atual;
			if(atual<menor && atual) menor = atual;
		}
		
		printf("%d %d\n", menor, maior);
		
	}
	
	
	
	return 0;
}