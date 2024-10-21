#include<stdio.h>

int main()
{
    int i, j, m, n;
    scanf("%d %d %d", &n, &j, &m);

    for ( i = 1; i <= n; i++)
        if (i % m == j % m) printf("%d mod %d = %d mod %d\n", i, m, j, m);
    
    return 0;
}
