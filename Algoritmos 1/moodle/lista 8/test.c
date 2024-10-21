#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int verificador(int n[], int i) {
    int j = 0, p = 2, sum = 0, r;
    for ( j; j <= i; j++, p++)
    {
        n[j] *= p;
        sum += n[j];
    }
    r = 11 - (sum % 11);
    if (r == 10 || r == 11) return 0;
    return r;
}
int main()
{
    int num, n[20], j, i = 0;
    char c[15];
    do
    {
        scanf("%d", &num);
        if (num == 0) break;
        do
        {
            n[i] = num % 10;
            num /= 10;
            i++;
        } while (num / 10 != 0);
        n[i] = num % 10;
        printf("%d", verificador(n, i));
    } while (1);
    
    return 0;
}
