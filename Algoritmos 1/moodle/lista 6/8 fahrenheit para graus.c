#include <stdio.h>
int main() {
    double c, f;

    for ( f = 50; f <= 150; f += 5)
    {
        c = (5 * (f -32))/9;
        printf("%.2lf celsius\n", c);
    }
    
    return 0;    
}