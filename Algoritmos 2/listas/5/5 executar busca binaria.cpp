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

void preenche_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = i;
}

void varios_x(int v[], int n)
{
    for (int x = 0; x < n; x++)
        printf("%d\n" , buscabinaria(x, n, v));
}

int main()
{
    int x = 5, v[100];
    
    preenche_vetor(v, 9);
    varios_x(v, 9);
    printf("\n-------------------\n\n");
    preenche_vetor(v, 14);
    printf("%d\n" , buscabinaria(9, 14, v));
    
    return 0;
}

/*
Execute buscabinaria com n = 9, com v[i] = i para cada i e com vários valores de x. Repita o
exercício com n = 14 e x = 9.
*/