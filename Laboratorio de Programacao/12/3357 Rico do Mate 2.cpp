/*
    Nesse exercicio, como não temos valores inteiros, para calcular o resto precisamos de uma formula especial, após isso, caso o resto seja 0
    significa que o anterior é o que foi o ultimo, porém há um problema, o que acontece quando o primeiro que ficou com 0? Para evitar erro
    mais um if foi acrescentado para evitar que seja pego um valor errado
*/
#include <stdio.h>
#include <math.h>

int main(){
    int n, i, vezes;
    float litros, cuia, resto;
    char nomes[11][13];

    scanf("%d %f %f", &n, &litros, &cuia);

    for(i = 0; i < n; i++){
        scanf("%s", &nomes[i]);
    }

    resto = litros - (int)(litros/cuia)*cuia;

    vezes = (int)(litros/cuia) % n;

    if(resto == 0){
        resto = cuia; 

        if(vezes - 1 < 0){
            vezes = n-1;
        } else{
            vezes -= 1;
        }
    }


    printf("%s %.1f\n", nomes[vezes], resto);

    return 0;
}