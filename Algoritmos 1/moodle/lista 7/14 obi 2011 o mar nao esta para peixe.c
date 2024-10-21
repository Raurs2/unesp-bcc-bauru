#include<stdio.h>
#include<math.h>

int main()
{
    int n, x0, y0, xf, yf, tot, i, lowX, lowY, highX, highY;
    scanf("%d", &n);
    lowX = lowY = highX = highY = tot = 0;
    for ( i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x0, &xf, &y0, &yf);

        if (i == 0) {
            lowX = x0;
            lowY = y0;
            highY = yf;
            highX = xf;
        }

        if (x0 < lowX) lowX = x0;
        if (y0 < lowY) lowY = y0;
        if (xf > highX) highX = xf;
        if (yf > highY) highY = yf;
    }
    tot = (highX - lowX) * (highY - lowY);
    
    printf("%d\n", tot);
    return 0;
}
