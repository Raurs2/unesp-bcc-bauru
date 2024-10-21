#include <stdio.h>
#include <math.h>

int cat(int c) {
    int i, j, a, b;
    for ( i = 1; i < c; i++)
        for ( j = 1; j <= i; j++)
        {
            a = i;
            b = j;
            if (a + b > c && a + c > b && b + c > a && c > b && c > a && c*c == b*b + a*a) return 1;
        }
    return 0;
}

int main() {
    int n, i;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        for (i = 1; i <= n; i++)
            if (cat(i)) printf("%d ", i);
    } while (1);
    
    return 0;
}