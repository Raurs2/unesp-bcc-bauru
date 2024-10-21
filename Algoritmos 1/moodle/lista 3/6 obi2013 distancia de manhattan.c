#include <stdio.h>

int main()
{
    int xm, ym, xr, yr, res_x, res_y;
    scanf("%d %d %d %d", &xm, &ym, &xr, &yr);
    if (xr > xm)
    {
        res_x = xr - xm;
    } else {
        res_x =  xm - xr;
    }
    if (yr > ym)
    {
       res_y =  yr - ym;
    } else {
       res_y =  ym - yr;
    }
    printf("%d",res_x+res_y);
    return 0;
}
