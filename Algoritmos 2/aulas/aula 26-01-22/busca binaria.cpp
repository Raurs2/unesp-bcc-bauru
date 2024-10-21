#include<stdio.h>

int BuscaBiInterativa(int v[], int n, int num)
{
    int meio, esq = 0, dir = n - 1;

    while (esq <= dir)
    {
        meio = (esq + dir) / 2;
        
        if (v[meio] == num) return meio;
        
        if (v[meio] < num) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
    
}

int BuscaBiRecursiva(int v[], int esq, int dir, int num)
{
    
    if (esq > dir) return -1;
    
    int meio = (esq + dir) / 2;
    
    if (v[meio] == num) return meio;

    if (v[meio] < num) return BuscaBiRecursiva(v, meio + 1, dir, num);
    return BuscaBiRecursiva(v, esq, meio - 1, num);

}

int main()
{
    
    return 0;
}
