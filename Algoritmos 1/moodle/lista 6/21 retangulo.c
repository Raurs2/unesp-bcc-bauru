#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char w[10];
    int i, j, d;
    scanf("%s", &w);
    d = strlen(w);
    for (i = 1; i <= 14; i++)
    {
        printf("* ");
    }
    printf("\n");
    for ( j = 1; j <= 3; j++)
    {   
        printf("*");
        if (j == 2)
        {
            for (i = 1; i <= 11; i++)
            {
                printf(" ");
            }
            printf("%s", w);
            for (i = 1; i <= 13 - d; i++)
            {
                printf(" ");
            }
        } else {
            for (i = 1; i <= 12; i++)
            {
            
            printf("  ");
            }
        }
        printf(" *\n");
    }
    for (i = 1; i <= 14; i++)
    {
        printf("* ");
    }
    return 0;    
}