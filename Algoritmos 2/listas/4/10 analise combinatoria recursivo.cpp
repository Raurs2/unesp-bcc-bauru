#include <cstdio>
#include <cstdlib>

double fat(double n)
{
    if (n == 0) return 1;
    else return n * fat(n - 1);
}

double comb(double n, double p)
{
    return fat(n) / (fat(p) * (fat(n-p)));
}

int main(){
    double n, p;

    while (scanf("%lf %lf", &n, &p) != EOF)
        printf("R: %.0lf\n", comb(n, p));
    
    return 0;
}    
