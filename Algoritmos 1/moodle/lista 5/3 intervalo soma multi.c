#include <stdio.h>
#include <math.h>
int main() {
    int n1, n2, multi = 1, sum = 0;
    scanf("%d %d", &n1, &n2);    
    for ( n1; n1 <= n2; n1++)
    {
        if (n1 % 2 == 0)
        {
            multi *= n1;
        } else if (n1 % 2 != 0)
        {
            sum += n1;
        }
    }
    printf("Multiplicacao Pares: %d\nSoma Imapres: %d", multi, sum);
    
    return 0;
}