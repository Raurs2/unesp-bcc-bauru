#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n = 1, i, sum = 0;
    do
    {
        if (n % 3 == 2 && n % 5 == 3 && n % 7 == 4)
            break;
        n++;
    } while (1);
    printf("%d", n);
    return 0;    
}