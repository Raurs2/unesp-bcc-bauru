#include <stdio.h>
#include <math.h>
int arredonda(double r) {
    if (r < 0 && r + (int)(r) == -0.5) return floor(r);
    if (r - (int)(r) == 0.5) return ceil(r);
    return round(r);
}
int main () {
    double r;
    scanf("%lf", &r);
    printf("arredonda = %d\n", arredonda(r));
    return 0;
}