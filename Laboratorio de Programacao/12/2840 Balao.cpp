#include<stdio.h>

/*
    peguei o volume de cada balao e depois peguei a parte inteira da divisao do litros/volume para saber quantos baloes encheram
    completamente
*/

int main()
{
    double pi = 3.1415, v, r, l;
    int result;
    
    scanf("%lf %lf", &r, &l);
    
    v = 4.0/3.0 * pi * (r * r * r);
    result = int(l/v);

    printf("%d\n", result);

    return 0;
}
