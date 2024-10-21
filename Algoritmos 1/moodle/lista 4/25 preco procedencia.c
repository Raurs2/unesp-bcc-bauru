#include<stdio.h>
sint main() {
    float preco;
    int id;
    char o[30];
    scanf("%f %d", &preco, &id);
    if (id == 1)
    {
        o = "sul";
    } else if (id == 2)
    {
        o = "Norte";
    } else if (id == 3)
    {
        o = "Leste";
    } else if (id == 4)
    {
        o = "Oeste";
    } else if (id == 5 || id == 6)
    {
        o = "Nordeste";
    } else if (id >= 7 && id <= 9)
    {
        o = "Sudeste";
    } else if (id >= 10 && id <= 20)
    {
        o = "Centrooeste";
    } else if (id >= 21 && id <= 30)
    {
        o = "Nordeste";
    } 
    printf("PRECO: %.2f\nORIGEM: %s", preco, o);
    return 0;
}