#include <stdio.h>
int primo(int n) {
    int i;
    if (n == 1 || n == 0) return 0;
    for (i = n/2; i >= 2; i--)
      if (n % i == 0) return 0;
    return 1;
}
int main() {
    int i, j, r, n, sum;
    for (n = 500; n <= 1300; n += 2)
        for (i = 2; i <= n/2; i++) {
            if (primo(i) && primo(n - i)) printf("%d = %d + %d\n", n, i, n-i);
            break;
        }
    return 0;    
}