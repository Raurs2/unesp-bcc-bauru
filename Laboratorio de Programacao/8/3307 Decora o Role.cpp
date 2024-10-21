#include<stdio.h>
#include<math.h>

// usei a formula da area da esfera pra descobrir o raio com base no raio troquei a cor e o valor do metro quadrado para printa

int main()
{
    int n;
    double pi = 3.14, r, p, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a);

        r = sqrt(a / (4.0 * pi));

        if (r <= 12)
        {
            p = a * 0.09;
            printf("vermelho = R$ %.2lf\n", p);
        } else if (r <= 15)
        {
            p = a * 0.07;
            printf("azul = R$ %.2lf\n", p);
        } else
        {
            p = a * 0.05;
            printf("amarelo = R$ %.2lf\n", p);
        }   
    }
    return 0;
}
