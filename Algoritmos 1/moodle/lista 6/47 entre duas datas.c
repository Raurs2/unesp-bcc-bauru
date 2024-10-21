#include<stdio.h>
int data_dias() {
    int a, m, d;
    scanf("%d %d %d", &d, &m, &a);
    d = d + m*30 + a*365;
    return d;
}
int main()
{
    int d1, d2;

    do
    {
        d1 = data_dias();
        d2 = data_dias();
        printf("%d - %d = %d\n", d2, d1, d2-d1);
    } while (d1 != d2);
    
    

    return 0;
}
