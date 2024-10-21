#include <stdio.h>
#include <math.h>
int main() {
    int i, n, p = 0;
    for ( i = 0; i < 5; i++)
    {
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            p += 1;
        }
    }
    printf("%d valores pares\n", p);
    return 0;
}