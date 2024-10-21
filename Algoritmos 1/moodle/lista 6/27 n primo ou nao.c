#include <stdio.h>

int primo(int n) {
    int i, sum;
    for ( i = 1, sum = 0; i <= n; i++)
            if (n % i == 0) sum += i;
        if (sum == 1 + n) return 1;
        else return 0;
}

int main() {
    int n, s;
    do
    {
        scanf("%d", &n);
        s = primo(n);
        if (s == 1) printf("primo\n");
        else printf("n eh primo\n");
        
    } while (n != 0);
    
    return 0;    
}