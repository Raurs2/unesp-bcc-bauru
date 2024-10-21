#include <stdio.h>
#include <math.h>
int main() {
    int extra, faltou, h;
    scanf("%d %d", &extra, &faltou);
    h = 60*(extra - (2/3*faltou));
    if (h > 2400)
    {
        printf("ganha 800\n");
    } else if (h <= 2400 && h > 1800)
    {
        printf("ganha 600\n");
    } else if (h <= 1800 && h > 1200)
    {
        printf("ganha 550\n");
    } else if (h <= 1200 && h > 600)
    {
        printf("ganha 400\n");
    } else if (h <= 600)
    {
        printf("ganha 350\n");
    }
    return 0;
}