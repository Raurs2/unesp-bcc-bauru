#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n1, n2, sum = 0;
    scanf("%d %d", &n1, &n2);
    
    do
    {
        if (n1 % 2 != 0)
        {
            sum += n2;
        }
        
        n1 /= 2;
        n2 *= 2;

        if (n1 == 1) sum += n2;

    } while (n1 != 1);

    printf("%d", sum);
    
    return 0;    
}