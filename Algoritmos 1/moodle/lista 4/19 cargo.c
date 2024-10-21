#include <stdio.h>
#include <math.h>
int main() {
    int cod;
    scanf("%d", &cod);
    switch (cod)
    {
    case 1:
        printf("Escriturário\n60%%\n");
        break;
    case 2:
        printf("Secretário\n40%%\n");
        break;
    case 3:
        printf("Caixa\n25%%\n");
        break;
    case 4:
        printf("Gerente\n5%%\n");
        break;
    case 5:
        printf("Diretor\nNão tem aumento\n");
        break;
    }
    return 0;
}