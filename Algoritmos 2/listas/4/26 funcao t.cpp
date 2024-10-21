#include <cstdio>
#include <cstdlib>

//Crie uma função para gerar a seqüência T, onde T(1) = 1, T(n)=T(n-1)+3 para n>=2.

int T(int n)
{
    if (n == 1)
    {
        printf(" 1 ");
        return 1;
    } else
    {
        printf(" %d ", n - 1);
        return T(n - 1) + 3;
    }
}

int main(){
    int n;
    do
    {
        scanf("%d", &n);
        if (n < 2) break;
        printf(" 3 = %d\n", T(n));
    } while (1);
    return 0;
}    
