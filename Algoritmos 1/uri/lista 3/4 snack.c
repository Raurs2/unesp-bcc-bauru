#include <stdio.h>
#include <math.h>

int main() {
    int id, qtd;
    scanf("%d %d", &id, &qtd);
     if (id == 1)
     {
        printf("Total: R$ %.2f\n", qtd * 4.0);
     } else if (id == 2)
     {
        printf("Total: R$ %.2f\n", qtd * 4.5);
     } else if (id == 3)
     {
        printf("Total: R$ %.2f\n", qtd * 5.0);
     } else if (id == 4)
     {
        printf("Total: R$ %.2f\n", qtd * 2.0);
     } else if (id == 5)
     {
        printf("Total: R$ %.2f\n", qtd * 1.5);
     }
     
     
    return 0;
}