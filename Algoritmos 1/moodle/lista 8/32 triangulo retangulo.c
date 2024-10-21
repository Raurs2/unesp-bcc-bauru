#include<stdio.h>
int tri(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) return 1;
    return 0;
}

int triRet(int a, int b, int c) {
    if (a > b && a > c && a*a == b*b + c*c) return 1;
    if (b > a && b > c && b*b == a*a + c*c) return 1;
    if (c > b && c > a && c*c == b*b + a*a) return 1;
    return 0;
}
int main()
{
    int a, b, c;
    do
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 || b == 0 || c == 0) break;
        if (tri(a, b, c) && triRet(a, b, c)) printf("Forma\n");
        else printf("nao Forma\n");
    } while (1);
    
    return 0;
}
