#include <stdio.h>
#include <math.h>
int main() {
    int id;
    scanf("%d", &id);
    if (id >= 0 && id <= 2)
    {
        printf("Recem-nascido");
    } else if (id >= 3 && id <= 11)
    {
        printf("Criança");
    } else if (id >= 12 && id <= 19)
    {
        printf("Adolescente");
    } else if (id >= 20 && id <= 55)
    {
        printf("Adulto");
    } else if (id > 55)
    {
        printf("idoso");
    }
    
    return 0;
}