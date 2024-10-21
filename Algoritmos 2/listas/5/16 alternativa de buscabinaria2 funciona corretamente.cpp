#include <stdio.h>

int buscabinaria2 (int x, int n, int v[]) {
int e, m, d;
e = 0; d = n;
while (e < d) // v[e-1] < x <= v[d]
{
m = (e + d)/2;
if (v[m] < x) e = m+1;
else d = m;
} // e == d
return d;
}

void preenche_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = i+2;
}

void varios_x(int v[], int n)
{
    for (int x = 0; x < n; x++)
        printf("%d\n" , buscabinaria2(x, n, v));
}

int main()
{
    int x = 5, v[100];
    
    preenche_vetor(v, 16);
    varios_x(v, 15);
    printf("%d\n" , buscabinaria2(-1, 16, v));
    
    return 0;
}

/*
Que acontece se trocarmos "while (e < d)" por "while (e <= d)"? Que acontece se trocarmos
"(e+d)/2" por "(e-1+d)/2"?
    se trocarmos por while (e <= d) da loop infinito e se trocarmos por (e-1+d)/2 não acontece nada
    0
0
0
1
2
3
4
5
6
7
8
9
10
11
12

0
0
0
1
2
3
4
5
6
7
8
9
10
11
12

*/