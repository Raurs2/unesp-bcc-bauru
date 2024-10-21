#include <stdio.h>
int perfeito(int n) {
    int sum, i;
    for ( i = 1, sum = 0; i < n; i++)
        if (n % i == 0) sum += i;
    if (sum == n) return 1;
    return 0;
}
int main() {
    int n;
    do
    {
        scanf("%d", &n);
        if (n == -1) break;
        if (perfeito(n)) printf("perfeito\n");
        else printf("n eh\n");
    } while (1);
    
    return 0;    
}