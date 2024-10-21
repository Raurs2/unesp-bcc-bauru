#include <stdio.h>
#include <math.h>
int main() {
    double n1, n2, n3, nf, n4;
    char c;
    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
    nf = (n1+n2+n3+n4)/4;
    printf("Media %.2lf\n", nf);
    if (nf > 7 && nf <= 10)
    {
        printf("Aprovado");
    } else if (nf > 5 && nf <= 7)
    {
        printf("Exame");
    } else if (nf <= 5 && nf >= 0)
    {
        printf("reprovado");
    }
    return 0;
}