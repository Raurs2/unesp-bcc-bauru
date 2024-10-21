#include <stdio.h>
int main () {
    int peso;
    scanf("%d", &peso);
    printf("gramas = %d\n", peso * 1000);
    printf("se engordar = %.2f\n", peso * 1000 * 1.05);
    return 0;
}