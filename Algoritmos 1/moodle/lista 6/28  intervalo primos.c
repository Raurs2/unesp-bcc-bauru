#include <stdio.h>

int primo(int n) {
    int i, sum;
    for ( i = 1, sum = 0; i <= n; i++)
            if (n % i == 0) sum += i;
        if (sum == 1 + n) return 1;
        else return 0;
}

int main() {
    int n, i, s;

    do
    {
        scanf("%d %d", &i, &n);
        if (n == 0 || i == 0) break;
        for (i; i <= n; i++)
        {
            s = primo(i);
            if (s == 1) printf("%d ", i);
        }
        printf("\n");
    } while (1);
    
    return 0;    
}