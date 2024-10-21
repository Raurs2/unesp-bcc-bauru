#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i = 0, r, x, y;

    printf("x < y\n");
    scanf("%d %d", &x, &y);
    srand(time(NULL));
    r = rand() % (y-x+1) + x;

    do
    {
        scanf("%d", &n);

        if (n > r) printf("Maior q n sorteado\n");
        if (n < r) printf("Menor q n sorteado\n");

        i++;
    } while (n != r);

    printf("acertou em tentativas: %d\n", i);
    
    return 0;    
}