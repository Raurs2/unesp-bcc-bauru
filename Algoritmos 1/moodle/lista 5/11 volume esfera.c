#include <stdio.h>
#include <math.h>
int main() {
    double r = 0, pi = 3.14159, v;
    for (r; r <= 20; r += 0.5)
    {
        v = 4.0 / 3.0 * pi * r * r * r;
        printf("RAIO = %.2lf VOLUME = %.2lf\n", r, v);
    }
    return 0;
}