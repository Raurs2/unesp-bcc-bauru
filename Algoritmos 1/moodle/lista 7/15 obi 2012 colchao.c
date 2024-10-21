#include<stdio.h>
#include<math.h>

#define pi 3.14159265359

int main()
{
    int a, b, c, h, l;
    char ca;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d", &h, &l);
    if (a < h && b < l || b < h && a < l || b < h && c < l || c < h && b < l || a < h && c < l || c < h && a < l) ca = 'S';
    else ca = 'N';
    printf("%c", ca);
    return 0;
}
