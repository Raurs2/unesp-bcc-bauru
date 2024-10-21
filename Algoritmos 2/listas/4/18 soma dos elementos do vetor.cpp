#include <cstdio>
#include <cstdlib>

int soma(int n, int v[])
{
    if (n == 0) return 0;
    else return v[n-1] + soma(n-1, v);
}

int main(){
    int n, v[1000];
    do
    {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        
        printf("R: %d\n", soma(n, v));
    } while (1);
    
    return 0;
}    
