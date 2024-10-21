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

int main()
{
    int x = 5, v[100];
    
    
    return 0;
}

/*
É verdade que m está em 0..n-1 sempre que a instrução if (v[m] < x) é executada?
    não, falso.
*/