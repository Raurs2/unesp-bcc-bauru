#include <stdio.h>
#include <math.h>
int main() {
    int i, r;
    scanf("%d %d", &i, &r);
    if (i >= 18 && i <= 24)
    {
        switch (r)
        {
        case 7:
            printf("Baixo\n");
            break;
        case 8:
            printf("Medio\n");
            break;
        case 9:
            printf("Alto\n");
        }
    } else if (i >= 25 && i <= 40)
    {
        switch (r)
        {
        case 4:
            printf("Baixo\n");
            break;
        case 5:
            printf("Medio\n");
            break;
        case 6:
            printf("Alto\n");
        }
    } else if (i >= 41 && i <= 70)
    {
        switch (r)
        {
        case 1:
            printf("Baixo\n");
            break;
        case 2:
            printf("Medio\n");
            break;
        case 3:
            printf("Alto\n");
        }
    } 
    return 0;
}