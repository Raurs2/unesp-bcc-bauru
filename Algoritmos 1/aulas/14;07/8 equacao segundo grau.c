#include <stdio.h>
#include <math.h>

int main() {
    float n1, n2, n3, nf;

    scanf("%f %f %f", &n1, &n2, &n3);
    
    if (n3 > n1)
    {
        nf = (n3 + n2)/2;
    } else if (n3 > n2)
    {
        nf = (n1 + n3)/2;
    } else
    {
        nf = (n1 + n2)/2;
    }

    if (nf >= 5)
    {
        printf("APROVADO\n");
    } else if (nf < 5 && nf >= 3)
    {
        printf("está em exame\n");
    } else
    {
        printf("REPROVADO\n");
    }
    printf("Media = %.2f", nf);
    return 0;
}