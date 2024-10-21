#include <stdio.h>
#include <math.h>

int main() {
    int n, f1 = 0, f2 = 1, fn = 0, i;
    scanf("%d", &n);
    printf("%d %d ", f1, f2);
    for ( i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;

        printf("%d", fn);
        if (i < n) printf(" ");
    }
    printf("\n");
    return 0;    
}