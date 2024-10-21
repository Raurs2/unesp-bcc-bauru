#include<stdio.h>

#define max 10

void select_sort_v1(int v[], int n)
{
    int aux;
    for (int i = 0; i < n - 1; i++)
    {
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

int selectSort_v2(int n, int v[]){
  int aux, i, j, pos_menor;
  for (i = 0; i < n-1; i++) {
    pos_menor = i;  
    for(j = i+1; j < n; j++)
      if (v[j] < v[pos_menor])
        pos_menor = j;
    if (pos_menor != i){
      aux = v[i];
      v[i] = v[pos_menor];
      v[pos_menor] = aux;
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
    select_sort_v1(v, n);
    print_vetor(v, n);
    return 0;
}
