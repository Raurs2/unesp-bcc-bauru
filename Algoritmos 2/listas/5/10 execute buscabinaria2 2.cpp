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
Execute a função buscabinaria2 com n = 15, com v[i] = i para cada i e com vários valores de
x.

*/