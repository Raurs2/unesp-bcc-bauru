#include <stdio.h>
#include <math.h>

int main() {
    int a;
    scanf("%d", &a);
    if (a == 3)
    {
        printf("Triangulo");
    } else if (a ==4)
    {
        printf("Quadrado");
    }
    else if (a == 5)
    {
        printf("pentagono");
    } else
    {
        printf("não identificado");
    }
    
    
    return 0;
}