#include <stdio.h>
#include <stdlib.h>

#define max 4

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenaVetor (int tam, int v[]) {
    int i, j;
    for (i = 0; i < tam-1; i++)
    for (j = i+1; j < tam; j++)
    if (v[i] > v[j]) troca(&v[i],&v[j]);
}

int main()
{
    int i, n;
    int a[max];

    do
    {
        for ( i = 0; i < max; i++)
            scanf("%d", &a[i]);
            
        ordenaVetor(max, a);

        for ( i = 0; i < max; i++)
            printf("%d ", a[i]);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
