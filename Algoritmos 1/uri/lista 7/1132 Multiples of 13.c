#include <stdio.h>
#include <math.h>

int main() {
    int x,y,sum=0, aux;
    scanf("%d %d", &x, &y);
    if (x > y)
    {
        aux = y;
        y = x;
        x = aux;
    }
    
    for ( x; x <= y; x++)
    {
        if (x % 13 != 0) sum += x;
    }
    printf("%d\n",sum);
    
    return 0;    
}