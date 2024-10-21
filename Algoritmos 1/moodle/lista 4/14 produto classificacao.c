#include <stdio.h>
#include <math.h>
int main() {
    int id;
    printf("ID\n");
    scanf("%d", &id);
    if (id == 1)
    {
        printf("Alimento não-perecível");
    } else if (id == 2 || id == 3 || id == 4)
    {
        printf("Alimento perecível");
    } else if (id == 5 || id == 6)
    {
        printf("Vestuário");
    } else if (id == 7)
    {
        printf("Higiene pessoal");
    } else if (id >= 8 && id <= 15)
    {
        printf("Limpeza e utensílios domésticos");
    } else {
        printf("Inválido");
    }
    return 0;
}
