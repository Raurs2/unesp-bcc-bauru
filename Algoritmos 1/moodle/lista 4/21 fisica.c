#include <stdio.h>
#include <math.h>
int main() {
    double n1, n2, n3, nf;
    char c;
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    nf = (n1*3 + n2*2 + n3*5) / 10;
    printf("Media %.2lf\n", nf);
    if (nf >= 8.5 && nf <= 10)
    {
        c = 'A';
    } else if (nf >= 7 && nf < 8.5)
    {
        c = 'B';
    } else if (nf >= 6 && nf < 7)
    {
        c = 'C';
    } else if (nf >= 5 && nf < 6)
    {
        c = 'D';
    } else if (nf < 5)
    {
        c = 'E';
    }
    printf("Conceito: %c", c);
    return 0;
}