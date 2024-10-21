
/* 
    Nesse exercicio veremos se na diagonal em que um bispo está, se há algum outro bispo na mesma diagonal, para isso podemos somar xey ou subtraor x e y 
    Valores iguais significa que estão na mesma diagonal, sendo assim, um vetor guardando os valores e depois conparalos é uma forma simples de resolver esse exercicio 
*/ 
#include <stdio.h> 
 
#define MAX 100001 
 
int main(){ 
    int i, j, n, x, y, somaXY[MAX], subXY[MAX], dominantes = 0, controle; 
 
    scanf("%d", &n); 
 
    for(i = 0; i < n; i++){ 
        scanf("%d %d", &x, &y); 
 
        somaXY[i] = x+y; subXY[i] = x-y; 
    } 
 
    for(i = 0; i < n; i++){ 
        controle = 1; 
 
        for(j = 0; j < n; j++){ 
            if(i != j){ 
                if(somaXY[i] == somaXY[j] || subXY[i] == subXY[j]){ 
                    j += n; controle = 0; 
                } 
            } 
        } 
 
        if(controle){ 
            dominantes++; 
        } 
    } 
 
    printf("%d\n", dominantes); 
 
    return 0; 
}