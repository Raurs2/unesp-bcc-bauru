#include <stdio.h>

void cabecalho(int d, int m, int a, int p){
    printf("UNESP- DEPARTAMNETO DE COMPUTACAO\n%d/%d/%d                PAG. %d\n\n", d, m, a, p);
}

int main()
{
    int d, m, a, p;
        scanf("%d %d %d %d", &d, &m, &a, &p);
        cabecalho(d, m, a, p);
    return 0;
}
