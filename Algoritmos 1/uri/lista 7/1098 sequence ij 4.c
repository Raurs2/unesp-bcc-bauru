#include <stdio.h>
#include <math.h>

int main() {
    double i, j, n1, n2;
    
    for (i = 0, j = 1, n1 = 1, n2 = 3; i <= 2; i += 0.2, j += 0.2, n1 += 0.2, n2 += 0.2)
    {
        for (j = n1; j <= n2; j++)
        {
            if (i == 0 || i > 0.9 && i < 1.1 || i > 1.8) printf("I=%.lf J=%.lf\n", i, j); 
                else printf("I=%.1lf J=%.1lf\n", i, j);
        }       
    }

    return 0;    
}