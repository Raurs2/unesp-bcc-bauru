#include<stdio.h>
int main()
{
    float c, f;
    printf("celsius: ");
    scanf("%f", &c);
    f = c * 9 / 5 + 32;
    printf("farenheit: %f", f);
    return 0;
}