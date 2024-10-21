#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
    peguei os input, troquei o p dependendo do metodo, e no final mostrei o resultado arredondado pra baixo
*/
int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        char metodo[20];
        scanf("%s", metodo);

        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);

        double p;
        if (!strcmp(metodo, "eye"))
        {
            p = 0.30*r + 0.59*g + 0.11*b;
        } else if (!strcmp(metodo, "mean"))
        {
            p = (r + g + b) / 3;
        } else if (!strcmp(metodo, "min"))
        {
            if (r <= g && r <= b)
            {
                p = r;
            } else if (g <= r && g <= b)
            {
                p = g;
            } else if (b <= g && b <= r)
            {
                p = b;
            }
        } else if (!strcmp(metodo, "max"))
        {
            if (r >= g && r >= b)
            {
                p = r;
            } else if (g >= r && g >= b)
            {
                p = g;
            } else if (b >= g && b >= r)
            {
                p = b;
            }
        }

        printf("Caso #%d: %.0lf\n", i, floor(p));
    }
    
    return 0;
}
