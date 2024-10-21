#include <stdio.h>

int primo(int n) {
    int i;
    if (n == 1 || n == 0) return 0;
    for (i = n/2; i >= 2; i--)
      if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n, s;
    do
    {
        scanf("%d", &n);
        if (primo(n)) printf("primo\n");
        else printf("n eh primo\n");
    } while (n != 0);
    
    return 0;    
}