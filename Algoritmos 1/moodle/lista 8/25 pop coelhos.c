#include <stdio.h>

int fibo(int n) {
    int f1 = 0, f2 = 1, fn, i;
    if (n = 1) return f1;
    for ( i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return f2;
    
}

int main() {
    int n;
    
    scanf("%d", &n);
    printf("\n%d", fibo(n));
    
    return 0;    
}