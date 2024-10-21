#include <stdio.h>
#include <math.h>

double permu(double n) {
    int i;
    double fat = 1;
    for ( i = 1; i <= n; i++)
        fat *= i;
    return fat;
}

double arranjo(double n, double k) {
    return permu(n)/permu(n-k);
}

double combi(double n, double k) {
    return arranjo(n, k)*permu(k);
}
int main() {
    double n, k;
    do
    {
        scanf("%lf %lf", &n, &k);
        if (n == 0) break;
        printf("Permu %.2lf\nArranjo %.2lf\nCombi %.2f\n", permu(n), arranjo(n, k), combi(n, k));
    } while (1);
    
    return 0;
}