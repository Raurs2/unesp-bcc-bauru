#include <stdio.h>
#include <math.h>
int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x < y + z && y < x + z && z < x + y)
    {
        if ((x == y) && (x == z) && (y == z))
        {
            printf("EQUILATERO\n");
        } else if ((x == y) || (x == z) || (y == z))
        {
            printf("ISOSCELES\n");
        } else {
            printf("escaleno\n");
        }
    } else {
        printf("nao eh triangulo\n");
    }
    return 0;
}