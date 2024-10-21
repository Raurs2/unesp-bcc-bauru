#include <stdio.h>

int buscabinaria2 (int x, int n, int v[]) {
int e, m, d;
e = -1; d = n;
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
        printf("%d\n" , buscabinaria2(x, n, v));
}

int main()
{
    int x = 5, v[100];
    
    preenche_vetor(v, 15);
    varios_x(v, 15);
    
    return 0;
}

/*
Confira a validade da seguinte afirmação: quando n+1 é uma potência de 2, a expressão
(e+d) é sempre divisível por 2, quaisquer que sejam v e x
    Falso

*/