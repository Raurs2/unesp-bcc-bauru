#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char n1[30], n2[30], n3[30];
    int r1, r2, r3;
    scanf("%s %s %s", &n1, &n2, &n3);
    r1 = strcmp(n1, "vertebrado");
    if (r1 == 0)
    {
        r2 = strcmp(n2, "ave");
        if (r2 == 0)
        {
            r3 = strcmp(n3, "carnivoro");
            if (r3 == 0)
            {
                printf("aguia\n");
            } else
            {
                printf("pomba\n");
            }
        } else
        {
            r3 = strcmp(n3, "onivoro");
            if (r3 == 0)
            {
                printf("homem\n");
            } else
            {
                printf("vaca\n");
            }
        }   
    } else
    {
        r2 = strcmp(n2, "inseto");
        if (r2 == 0)
        {
            r3 = strcmp(n3, "hematofago");
            if (r3 == 0)
            {
                printf("pulga\n");
            } else
            {
                printf("lagarta\n");
            }
        } else
        {
            r3 = strcmp(n3, "hematofago");
            if (r3 == 0)
            {
                printf("sanguessuga\n");
            } else
            {
                printf("minhoca\n");
            }
        }
    }
    return 0;
}