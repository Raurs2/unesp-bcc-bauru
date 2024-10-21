#include <stdio.h>
#include <math.h>

int main() {
    double custo, h, r, a, pi = 3.14, tinta, total;
    //lata = 50 reais 5 litros 3 m2
    printf("Informe altura e raio ");
    scanf("%lf %lf", &h, &r);
    
    a = (2 * pi * pow(r, 2)) + (2*pi*r*h);
    tinta = a * 5 / 3;
    total = ceil(tinta / 5);
    custo = total * 50;

    printf("Latas: %d\nCusto: %.2lf\n", (int)total, custo);

    return 0;
}