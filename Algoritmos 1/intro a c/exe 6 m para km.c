#include<stdio.h>
int main()
{
    float m, km;
    printf("m/s: ");
    scanf("%f", &m);
    km = m * 3.6;
    printf("km/h: %f", km);
    return 0;
}
