#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c, delta, r1, r2;

    scanf("%lf %lf %lf", &a, &b, &c);

    delta = pow(b, 2) - 4 * a * c;

    if (delta < 0)
    {
        printf("Nao existem raizes reais");
    } else if (delta >= 0)
    {
        r1 = (-b + sqrt(delta)) / (2 * a);
        r2 = (-b - sqrt(delta)) / (2 * a);
        
        printf("Raiz 1 = %.2lf\nRaiz 2 = %.2lf\n", r1, r2);
    }
    
    return 0;
}