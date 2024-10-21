#include <stdio.h>

int soma(int n, int x)
{
    if (n == 0 && x != 0)
        return 1 + soma(n, x-1);
    if (x == 0)
        return 0;
    return 1 + soma(n-1, x);
}

int main ()
{
    int n, x;
    scanf("%d %d", &x, &n);
    
    printf("%d", soma(n, x));
    
    return 0;
}
