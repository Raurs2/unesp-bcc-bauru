#include <stdio.h>

int primo(int n) {
    int i;
    if (n == 1 || n == 0) return 0;
    for ( i = n/2; i >= 2 ; i--)
        if (n % i == 0) return 0;
    return 1;   
}

int decompor(int n) {
    int i = 2;
    do
    {
        if (primo(i))
            while (n % i == 0)
                {
                    n /= i;
                    printf("%d ", i);
                }
        i++;
    } while (n != 1);
}

int main() {
    int n;
    scanf("%d", &n);
    decompor(n);
    return 0;    
}