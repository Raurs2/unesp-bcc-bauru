#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inverso(int n[], int num) {
    int i = 0, j = 0, sum = 0;
    
        do
        {
            n[i] = num % 10;
            num /= 10;
            i++;
        } while (num / 10 != 0);
        n[i] = num % 10;
        for ( j; j <= i; j++)
        {
            printf("%d", n[j]);
        }
}
int main()
{
    int num, n[20];
    do
    {
        scanf("%d", &num);
        if (num == 0) break;
        inverso(n, num);
        //printf("%d", n);
    } while (1);
    
    return 0;
}
