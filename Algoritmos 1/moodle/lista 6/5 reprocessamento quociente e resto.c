#include <stdio.h>
int main() {
    int quociente = 0, n1, n2;

    scanf("%d %d", &n1, &n2);

    while (n1 >= n2)
    {
        quociente++;
        n1 -= n2;
    }
    
    printf("Resto: %d\nQuociente: %d\n", n1, quociente);
    
}