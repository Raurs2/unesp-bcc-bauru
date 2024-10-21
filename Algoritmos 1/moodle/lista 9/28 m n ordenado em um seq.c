#include <stdio.h>
#include <stdlib.h>

#define max 100
#define maxX 200

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
    int i, x, y, ini, j, k, xy;
    int m[max], n[max], vetor[maxX];

    do
    {
        scanf("%d", &x);
        for ( i = 0, ini = 0; i < x; i++, ini++)
        {
            scanf("%d", &m[i]);
            vetor[ini] = m[i];
        }
        scanf("%d", &y);
        for ( i = 0; i < y; i++, ini++)
        {
            scanf("%d", &n[i]);
            vetor[ini] = n[i];
        }
        xy = x + y;
        for (i = 0; i < xy - 1; i++)
        {
            for (j = i + 1; j < xy; j++)
            {
                if (vetor[j] == vetor[i])
                {
                    k = j;

                    while (k < xy)
                        vetor[k] = vetor[k + 1], k++;

                    xy--;
                    j--;
                }
            }
        }
        ordenaVetor(xy, vetor);
        for ( i = 0; i < xy; i++)
        {
            printf("%d ", vetor[i]);
        }
        

    } while (n != 0);
    return 0;
}
