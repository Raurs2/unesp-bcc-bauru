#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);
    i = 1;
    do
    {
        if (i % 2 != 0)
        {
            n--;
            sum += i;
        }
        i++;
    } while (n != 0);
    printf("%d", sum);
    
    return 0;    
}