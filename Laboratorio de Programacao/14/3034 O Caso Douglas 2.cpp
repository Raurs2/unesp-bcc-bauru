/*
    Nesse exercicio, após criarmos um vetor com numeros primos, só precisamos ver se x+2 possui valor, se sim, é primo, então só conferimos as 
    outras condições e já podesmos responder o exercicio
*/
#include <stdio.h>
#include <math.h>

void crivo(int primos[]){
    int raiz = sqrt(10005), i, j;

    for(i = 2; i <= 10005; i++){
        primos[i] = i;
    }

    for(i = 2; i <= raiz; i++){
        if(primos[i] == i){
            for(j = i+i; j <= 10005; j += i){
                primos[j] = 0;
            }
        }
    }
}

int main(){
    int n, i, x, primos[10005] = {}; crivo(primos);

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &x); x += 1;

        if(x%7 == 0 && x%2 && primos[x+2]){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
    }

    return 0;
}