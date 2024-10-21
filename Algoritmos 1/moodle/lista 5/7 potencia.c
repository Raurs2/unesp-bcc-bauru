#include <stdio.h>
#include <math.h>
int main() {
    int x, y, r;
    scanf("%d %d", &x, &y);
    r = x;
    for (y; y > 1; y--)
    {
        x *= r;
    }
    printf("%d", x);
    return 0;
}