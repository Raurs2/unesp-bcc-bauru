#include <stdio.h>
#include <math.h>
double vol(double r) {
    double pi = 3.14159;
    return 4.0 / 3.0 * pi * r * r * r;
}
int main () {
    double r;
    scanf("%lf", &r);
    printf("VOLUME = %.3lf\n", vol(r));
    return 0;
}