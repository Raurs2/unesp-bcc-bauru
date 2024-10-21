
#include<stdio.h>

double f(double x, double y) {
if (x >= y)
    return (x + y)/2;
    else return f (f (x+2, y-1), f (x+1, y-2));
}
 
double simplesF(double x, double y)
{
    return (x + y) / 2;
}

int main()
{
    int x = 1, y = 10;

    //scanf("%d %d", &x, &y);

    printf("%lf\n", f(x, y));
    printf("%lf\n", simplesF(x, y));
 
    return 0;
}

// Qual é o valor de f (1,10)? 
// 5.500000