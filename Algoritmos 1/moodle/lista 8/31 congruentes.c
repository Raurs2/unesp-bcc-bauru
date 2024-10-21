#include<stdio.h>
void congruente(int n, int j, int m) {
    int i;
    for ( i = 1; i <= n; i++)
        if (i % m == j % m) printf("%d mod %d = %d mod %d\n", i, m, j, m);
}
int main()
{
    int j, m, n;
    scanf("%d %d %d", &n, &j, &m);
    congruente(n, j, m);
    return 0;
}
