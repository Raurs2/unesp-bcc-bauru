
#include<stdio.h>

double calculaSerie(double n)
{
    if (n == 1)
    {
        return 2;
    }
    return (n*n+1)/n + calculaSerie(n-1);
    
}
 

int main()
{
    double n = 10;

    printf("%lf", calculaSerie(n));
 
    return 0;
}