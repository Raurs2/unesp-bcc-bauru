#include <stdio.h>
#include <stdlib.h>

#define MAX 4

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

int isLatinSquare(int a[MAX][MAX], int lin, int col) {
    int i, j, v[lin], v2[lin], k;
    if (lin == col)
    {
        for ( i = 0; i < lin; i++)
        {
            v[i] = i+1;
            for ( j = 1; j < col; j++)
            {
                if (a[i][0] == a[i][j] || a[0][i] == a[j][i]) return 0;
            }
        }
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                v2[j] = a[i][j];
            }
            ordenaVetor(lin, v2);
            for ( k = 0; k < lin; k++)
            {
                if (v[k] != v2[k]) return 0;
            }
        }
        
        return 1;
    }
    return 0;
}

int main() {
    int i, j, n;
    int a[MAX][MAX];
    do
    {
        for ( i = 0; i < MAX; i++)
            for ( j = 0; j < MAX; j++)
                scanf("%d", &a[i][j]);
            
        if (isLatinSquare(a, MAX, MAX)) printf("e quadrado latino!\n");
        else printf("nao e quadrado latino!\n");
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}