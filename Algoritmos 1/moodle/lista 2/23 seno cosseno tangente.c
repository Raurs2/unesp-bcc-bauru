#include <stdio.h>
#include <math.h>
int main () {
    double graus, radianos;

    printf("Informe graus: ");
    scanf("%f", &graus);
    radianos = graus * 3.14 /180;

    printf("Seno= %.2lf\n", sin(radianos));
    printf("Cosseno= %.2lf\n", cos(radianos));
    printf("Tangente= %.2lf\n", tan(radianos));
}