#include<stdio.h>

int main()
{
    int n, x, i;
    double f1 = 0, f2 = 1, fn[61];
    scanf("%d", &x);
    fn[0] = 0;
    fn[1] = 1;
    for (i = 2; i < 61; i++)
    {
        fn[i] = f1 + f2;
        f1 = f2;
        f2 = fn[i];
    }
    for ( i = 0; i < x; i++)
    {
        scanf("%d", &n);
        printf("Fib(%d) = %.0lf\n", n, fn[n]);
    }
    
    return 0;
}