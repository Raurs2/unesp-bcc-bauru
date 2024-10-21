#include <stdio.h>
#include <math.h>
int main() {
    int id;
    float preco;
    printf("forma e preco\n");
    scanf("%d %f", &id, &preco);
    if (id == 1)
    {
        preco = preco * 0.90;
    } else if (id == 2)
    {
        preco = preco * 0.95;
    } else if (id == 4)
    {
        preco = preco * 1.1;
    }
    printf("vai pagar: %.2f", preco);
    return 0;
}