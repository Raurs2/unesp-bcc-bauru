#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    usei a funcao de ordenar, e fui vendo se tinha repetidas eu incrementava as repetidas
    depois subtrai as repetidas do total para ter as diferentes
*/

int comparacao(const void *pv1, const void *pv2)
{
  int v1 = *(int *)pv1;
  int v2 = *(int *)pv2;
  return v1 - v2;
}

int main() {
    int n, r = 0, d, fig[10001];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &fig[i]);

    qsort(fig, n, sizeof(fig[0]), comparacao);

    for (int i = 0; i < n; i++)
        if (fig[i] == fig[i+1]) r++;

    d = n - r;

    printf("%d\n%d\n", d, r);
    
    return 0;
}