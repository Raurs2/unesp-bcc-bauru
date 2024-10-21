#include<stdio.h>

void Insercao(int n, float *vet) {
    float aux;
    int i, j;
    for (i = 1; i < n; i++) {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && aux < vet[j] ) {
            vet[j+1] = vet[j];
            j = j - 1;
        }
        vet[j+1] = aux;
    }
}

void InsercaoReescrito(int n, float *vet) {
    float aux;
    int i, j;
    for (i = 1; i < n; i++) {
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && aux > vet[j] ) {
            vet[j+1] = vet[j];
            j = j - 1;
        }
        vet[j+1] = aux;
    }
}

int main()
{
    float vet[] = {0, 2, 1, 9, 4, 5};

    Insercao(6, vet);

    for (int i = 0; i < 6; i++)
        printf("%.0f ", vet[i]);
    
    InsercaoReescrito(6, vet);

    printf("\n");

    for (int i = 0; i < 6; i++)
        printf("%.0f ", vet[i]);

    return 0;
}
