#include <stdio.h>
#include <math.h>
int main() {
    int n, teste = 1;
    scanf("%d", &n);

    while (n != -1)
    {
        printf("Teste %d\n", teste++);
        printf("%d\n\n", (int)(pow(4, n) + pow(2, n + 1) + 1));

        scanf("%d", &n);
    }
    return 0;
}