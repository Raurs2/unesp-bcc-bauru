#include <stdio.h>
#include <math.h>

int main() {
    int h1 = 150, h2 = 110, t = 0;
    while (h1 > h2)
    {
        h1 += 2;
        h2 += 3;
        t++;
    }
    printf("%d", t);
    return 0;    
}