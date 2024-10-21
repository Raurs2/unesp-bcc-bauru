#include <stdio.h>
#include <stdlib.h>

#define maxA 3
#define maxB 2
#define maxC 5

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
    int i, n, tot, ini = 0;
    int a[maxA], b[maxB], c[maxC];

    do
    {
        for ( i = 0; i < maxA; i++)
            scanf("%d", &a[i]);
        for ( i = 0; i < maxB; i++)
            scanf("%d", &b[i]);
        
        for ( i = 0; i < maxA; i++, ini++)
            c[ini] = a[i];
        for ( i = 0; i < maxA; i++, ini++)
            c[ini] = b[i];
        ordenaVetor(maxC, c);

        for ( i = 0; i < maxC; i++)
            printf("%d ", c[i]);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
