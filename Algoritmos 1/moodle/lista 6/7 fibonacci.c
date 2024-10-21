#include <stdio.h>
int main() {
    int n, i, f1 = 0, f2 = 1, fn;
    scanf("%d", &n);

    for (i = 3; i < n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    printf("%d", fn);
    
    return 0;    
}