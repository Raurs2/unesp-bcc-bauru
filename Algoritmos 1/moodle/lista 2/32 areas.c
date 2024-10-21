#include <stdio.h>
#include <math.h>

int main() {
    int hr, min;

    printf("informe hr.min: ");
    scanf("%d.%d", &hr, &min);

    min = min + hr * 60;

    printf("em minutos = %d\n", min);
    return 0;
}