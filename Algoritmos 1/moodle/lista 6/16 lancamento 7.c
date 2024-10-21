#include <stdio.h>
#include <math.h>

int main() {
    int d1, d2;
    for (d1 = 1; d1 <= 6; d1++)
    {
        for ( d2 = 1; d2 <= 6; d2++)
        {
            if (d1 + d2 == 7)
            {
                printf("%d %d\n", d1, d2);
            }   
        }
    }
    
    return 0;    
}