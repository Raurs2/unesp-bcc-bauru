#include<stdio.h>
int main()
{
    int a, b, troca;
    printf("digite a e b: ");
    scanf("%d %d", &a, &b);
    troca = a;
    a = b;
    b = troca;
    printf("a: %d\nb: %d", a, b);
    return 0;
}
