#include<stdio.h>

#define max 10

void insert_sort_v1(int v[], int n)
{
    int aux, i, j;
    for (i = 1; i < n; i++)
    {
        aux = v[i];
        for (j = i - 1; (j >= 0) && (aux < v[j]); j--)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = aux;
    }
}

void select_sort_v2(int v[], int n)
{
    int aux, menor;
    for (int i = 0; i < n - 1; i++)
    {
        menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void print_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void scan_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

int main()
{
    int v[max], n = 10;
    
    scan_vetor(v, n);
    print_vetor(v, n);
    insert_sort_v1(v, n);
    print_vetor(v, n);
    return 0;
}
