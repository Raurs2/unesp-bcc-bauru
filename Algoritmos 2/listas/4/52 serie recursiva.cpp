
#include<stdio.h>

double serie(double n, double x)
{
    if (n <= 1)
    {
        return x/1;
    } else
    {
        return x/n + serie(n-1, x+1);
    }
    
}

int main()
{
    double n= 10, x = 1;


    printf("%.2lf", serie(n, x));
 
    return 0;
}
