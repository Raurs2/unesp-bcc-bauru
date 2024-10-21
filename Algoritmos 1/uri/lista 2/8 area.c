#include <stdio.h>
 
int main() {
    double a, b, c, pi = 3.14159, aTri, aCirc, aTrap, aQuad, aRet;
    scanf("%lf %lf %lf", &a, &b, &c);
    aTri = a * c / 2;
    aCirc = pi * c * c;
    aTrap = (a +b) * c / 2;
    aQuad = b * b;
    aRet = a * b;
    printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", aTri, aCirc, aTrap, aQuad, aRet);
    return 0;
}