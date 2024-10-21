#include <stdio.h>
int main() {
    int n, teste = 1, base, inc, i;
    scanf("%d", &n);

    while (n != -1)
    {
        base = 2;
        inc = 1;

        for (i = 1; i <= n; i++)
        {
            base += inc;
            inc *= 2;
        }
        
        printf("Teste %d\n", teste++);
        printf("%d\n\n", base*base);

        scanf("%d", &n);
    }
    return 0;
}