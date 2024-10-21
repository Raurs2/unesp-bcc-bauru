#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b && a < c)
    {
        printf("%d + %d = %d", b, c, b+c);
    } else if (b < a && b < c)
    {
        printf("%d + %d = %d", a, c, a+c);
    } else
    {
        printf("%d + %d = %d", a, b, a+b);
    }    
    return 0;
}