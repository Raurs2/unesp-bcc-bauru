#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i = 0, r;
    
    srand(time(NULL));
    r = rand() % 500;
    do
    {
        scanf("%d", &n);

        if (n > r) printf("Maior q n sorteado\n");
        if (n < r) printf("Menor q n sorteado\n");

        i++;
    } while (n != r);

    printf("acertou em tentativas: %d\n", i);
    if (i <= 3) printf("Muito sortudo\n");
    else if (i <= 6) printf("Sortudo\n");
    else if (i <= 10) printf("Normal\n");
    else if (i > 10) printf("tente dnv\n");
    
    return 0;    
}