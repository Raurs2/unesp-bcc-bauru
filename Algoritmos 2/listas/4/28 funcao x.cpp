#include <cstdio>
#include <cstdlib>

int X (int N, int M){
    if (N == M || M == 0)
        return 1;
    return X(N -1,M) + X(N -1,M -1);
}

int main(){
    printf("a) %d\n", X(5, 3));
    printf("b) %d\n", X(2, 2));
    printf("c) %d\n", X(3, 5));
    return 0;
}
/* 
a) Qual o valor de X(5,3)?
    10
b) Qual o valor de X(2,2)?
    1
c) Qual o valor de X(3,5)?
    nada, pois x(n -1, m) nunca tera condicao de parada
d) Quantas chamadas serão feitas nas avaliações acima?
    a - 6
    b - 1
    c - buga, pois x(n -1, m) nunca tera condicao de parada
*/