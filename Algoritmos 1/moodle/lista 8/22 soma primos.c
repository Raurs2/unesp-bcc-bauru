#include <stdio.h>

int primo(int n) {
    int i;
    if (n == 1 || n == 0) return 0;
    for (i = n/2; i >= 2; i--)
      if (n % i == 0) return 0;
    return 1;
}
int main() {
    int n, sum = 0;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        if (primo(n)) sum += n;
    } while (1);
    printf("%d", sum);
    return 0;    
}