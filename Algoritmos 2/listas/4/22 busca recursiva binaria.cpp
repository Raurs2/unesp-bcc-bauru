#include <cstdio>
#include <cstdlib>

int BuscaBiRecursiva(int v[], int esq, int dir, int num)
{
    
    if (esq > dir) return -1;
    
    int meio = (esq + dir) / 2;
    
    if (v[meio] == num) return meio;

    if (v[meio] < num) return BuscaBiRecursiva(v, meio + 1, dir, num);
    return BuscaBiRecursiva(v, esq, meio - 1, num);

}

int main(){
    int n, v[1000], num;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        scanf("%d", &num);
        
        printf("Pos: %d\n", BuscaBiRecursiva(v, 0, n-1, num) + 1);
    } while (1);
    
    return 0;
}    
