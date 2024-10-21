#include <stdio.h>
int triangular(int n) {
    int i = 1;
    for ( i = 1; i <= n/2; i++)
        if (i*(1+i)*(2+i) == n)
            return 1;
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    if (triangular(n)) printf("eh\n");
    else printf("nao eh\n");
    return 0;    
}