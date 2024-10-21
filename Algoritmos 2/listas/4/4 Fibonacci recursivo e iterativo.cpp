#include <stdio.h>
#include <stdlib.h>

int fiboIt(int n)
{
    int i, fn = 1, f1 = 0, f2 = 1;
    if (n == 1) return f1;
    if (n == 2) return f2;
    for (i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

int fiboRecu(int n)
{
    if (n < 2) return n;
    return fiboRecu(n-1) + fiboRecu(n - 2);
    
}

int main(){
    printf("sequencia no it comeca na posicao 1, 2, 3...\nSequencia no Recu comeca na posicao 0, 1, 2...\n");
    printf("IT %d\n", fiboIt(6));
    printf("Recu %d\n", fiboRecu(5));
    return 0;
}    
    
