#include<stdio.h>
float soma(int n){
    int i;
    float sum = 0;
    for ( i = 1; i <= n; i++)
    {
        sum += i/(n-i+1.0);
    }
    return sum;
}
int main()
{
    int n;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%.2f\n", soma(n));
    } while (1);
    
    return 0;
}
