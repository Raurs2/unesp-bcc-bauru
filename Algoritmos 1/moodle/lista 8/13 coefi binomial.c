#include <stdio.h>

double fatorial(double x){
    double fat = 1;
    for (x; x > 0; x--)
        fat *= x;
    return fat;
}

int main()
{
    double n, k, r;
    do
    {
        scanf("%lf %lf", &n, &k);
        if ((int)(n) == 0 || (int)(k) == 0) break;
        r = fatorial(n)/fatorial(k)*fatorial(n-k);
        printf("%.1lf", r);
    } while (1);
    return 0;
}
