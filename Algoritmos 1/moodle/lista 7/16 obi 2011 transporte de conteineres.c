#include<stdio.h>
#include<math.h>

#define pi 3.14159265359

int main()
{
    int a, b, c, x, y, z, max, an, ac, floor, h;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    an = x*y;
    ac = a*b;
    floor = an/ac;
    h = z / c;
    max = floor * h;
    printf("%d\n", max);
    return 0;
}
