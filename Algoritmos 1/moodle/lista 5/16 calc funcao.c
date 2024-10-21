#include <stdio.h>
#include <math.h>

int main()
{
    double x, h, f, g;
    int i;

    for (x = 1; x <= 10; x++)
    {
        h = pow(x, 2) - 16;
        
        if (h >= 0)
        {
            f = h;
        } else {
            f = 1;
        }
        
        if (f == 0)
        {
            g = pow(x, 2) + 16;
        } else if (f > 0)
        {
            g = 0;
        }
        
        printf("H = %.2lf F = %.2lf G = %.2lf\n\n", h, f, g);
    }
    
    return 0;
}
