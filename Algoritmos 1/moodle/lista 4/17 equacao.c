#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c, d, u, v, x, y;
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &u, &v);
    x = ((d / ((a*d)-(b*c))) * u) - ((b/((a*d)-(b*c)))*v);
    y = -c/(a*d-b*c)*u + a/(a*d-b*c)*v;
    printf("x = %.2lf\ny = %.2lf", x, y);
    return 0;
}