#include <stdio.h>

double pot(int x, int n)
{
    if (n == 0) return 1;

    if ( n > 0)
    {
        if (n == 1)
            return x;
        else
            return x * pot(x, n-1);
    } else
    {
        if (n == -1)
            return 1/x;
        else
            return 1/x * pot(x, n+1);
    }
    
}

int main ()
{
    int n, x;
    scanf("%d %d", &x, &n);
    
    printf("%.2lf", pot(x, n));
    
    return 0;
}
