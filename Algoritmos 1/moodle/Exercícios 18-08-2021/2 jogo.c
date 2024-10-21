#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i = 0, r;
    
    srand(time(NULL));
    r = rand() % 1000 + 1;

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