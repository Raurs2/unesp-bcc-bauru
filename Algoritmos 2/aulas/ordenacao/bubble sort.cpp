#include<stdio.h>

#define max 10

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

void bubble_sort(int v[], int n)
{
    int i, j, isTroca = 1, aux;
    for ( i = 0; i < n-1 && isTroca; i++)
    {
        isTroca = 0;
        for ( j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                isTroca = 1;
            }
        }
    }
}

int main()
{
    int v[max], n = 10;
    
    scan_vetor(v, n);
    print_vetor(v, n);
    bubble_sort(v, n);
    print_vetor(v, n);
    return 0;
}

// 1 9 2 8 3 7 4 6 5 0
