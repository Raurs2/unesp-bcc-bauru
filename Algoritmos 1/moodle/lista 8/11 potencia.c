#include <stdio.h>
void potencia(double x, double y, double* r){
    int i;
    *r = 1;
    for (i = 1; i <= y; i++)
    {
        *r *= x;
    }
}
int main()
{
    int i;
    double x, y, r;
    for ( i = 0; i < 15; i++)
    {
        scanf("%lf %lf", &x, &y);
        potencia(x, y, &r);
        printf("%.1lf^%.1lf = %.1lf\n\n", x, y, r);
    }
    
    return 0;
}
