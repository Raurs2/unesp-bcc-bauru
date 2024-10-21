#include <stdio.h>
#include <math.h>

int main() {
    int x, y = 2002;
    do
    {
        scanf("%d", &x);

        if (x == y) break;
        if (x < y || x > y) printf("Senha Invalida\n");

    } while (1);
    printf("Acesso Permitido\n");
    return 0;    
}