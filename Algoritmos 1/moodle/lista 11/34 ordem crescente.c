#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

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

int separar(char str[], int num[]) {
    char *c;
    int i = 0;
    c = strtok (str," .,-");
        while (c != NULL) {
            num[i] = atoi(c);
            c = strtok(NULL," .,-");
            i++;
        }
        
    return i;
}

int main () {
    char str[MAX];
    int i, n, num[MAX], d;
    do
    {
        gets(str);
        d = separar(str, num);
        ordenaVetor(d, num);
        for ( i = 0; i < d; i++)
        {
            printf("%d ", num[i]);
        }
        
        scanf("%d", &n);
    } while (n != 0);
}