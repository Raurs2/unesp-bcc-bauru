#include <stdio.h>

int primo(int n) {
    int i, sum;
    if (n == 2) return 0;
    for ( i = 1, sum = 0; i <= n; i++)
            if (n % i == 0) sum += i;
    if (sum == 1 + n) return 1;
    else return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", primo(n));
    return 0;    
}