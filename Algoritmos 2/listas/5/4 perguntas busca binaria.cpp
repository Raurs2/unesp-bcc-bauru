#include <stdio.h>

// A função abaixo recebe um vetor crescente v[0..n-1]
// com n >= 1 e um número x.
// Ela devolve um índice j em 0..n tal que v[j-1] < x <= v[j].
int buscabinaria (int x, int n, int v[]) {
    int e, m, d;
    if (v[n-1] < x) return n;
    if (x <= v[0]) return 0; // agora v[0] < x <= v[n-1]
    e = 0; d = n-1;
    while (e < d-1) {
        m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;
    }
    return d;
}

int main()
{
    int x = 5, n = 4, v[4] = {2, 3, 5, 6};
    printf("%d\n" , buscabinaria(x, n, v));
    return 0;
}

/*
a) Que acontece se "while (e < d-1)" for trocado por "while (e < d)"? ou por "while (e <= d-1)"?
    ocorre um loop infinito
b) Que acontece se "if (v[m] < x)" for trocado por "if (v[m] <= x)"?
    se x for igual a algum valor do vetor, a posicao dele estara adianta. exemplo: {4, 5, 6} se x = 5, pos_x = 2
c) Que acontece se "e = m" for trocado por "e = m+1" ou por "e = m-1"? E se "d = m" for tro-
cado por "d = m+1" ou por "d = m-1"?
    por e = m+1 aumenta em 1 a posicao do x, se trocar por e = m-1 da loop infinito,
    por d = m-1 diminui em 1 a posicao do x, se trocar por d = m+1 da loop infinito, 
*/