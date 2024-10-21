#include<stdio.h>
#include<math.h>

#define pi 3.14159265359

int main()
{
    int x, y, z, r, d, e;
    char c;
    scanf("%d %d %d %d", &x, &y, &z, &r);
    d = x*x + y*y + z*z;
    e = 4*r*r;
    if (d <= e) c = 'S';
    else c = 'N';
    printf("%c\n", c);
    return 0;
}
