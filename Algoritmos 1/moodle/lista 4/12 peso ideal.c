#include <stdio.h>
#include <math.h>
int main() {
    float p, h, ideal, s;
    printf("1 - homem 2 - mulher, peso, altura\n");
    scanf("%d %d %d", &s, &p, &h);
    if (s == 1)
    {
        ideal = 72.7 * h - 58; 
    } else if (s == 1){
        ideal = 62.1 * h - 44.7;
    }
    if (p > ideal)
    {
        printf("ACIMA\n");
    } else if (p < ideal)
    {
        printf("ABAIXO\n");
    } else {
        printf("PESO IDEAL\n");
    }    
    return 0;
}