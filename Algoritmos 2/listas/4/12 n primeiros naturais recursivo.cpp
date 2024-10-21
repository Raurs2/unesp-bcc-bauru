#include <cstdio>
#include <cstdlib>
//Escreva uma função recursiva que determine a soma dos N primeiros números naturais. Fa-
//ça um programa, com reprocessamento, que utilize esta função.

int soma(int n)
{
    if (n == 1) return 1;
    else return n + soma(n - 1);
}

int main(){
    int n;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", soma(n));
    } while (1);
    
    return 0;
}    
