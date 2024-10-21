#include<stdio.h>
#include<string.h>

int main()
{
    float a, g, ra, rg, xa, xg;
    char c;
    
        scanf("%f %f %f %f", &a, &g, &ra, &rg);
        xa = a / ra;
        xg = g / rg;
        if (xa > xg) c = 'A';
        else if (xa <= xg) c = 'G';
        
        printf("%c\n", c);

    return 0;
}
