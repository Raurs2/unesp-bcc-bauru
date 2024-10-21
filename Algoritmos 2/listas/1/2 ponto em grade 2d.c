#include <stdio.h>

typedef struct 
{
    int x, y;
} Ponto;

dentro_fora(Ponto p, int v1, int v2)
{
    if (p.x >= v1 && p.x <= v2 && p.y >= v1 && p.y <= v2)
        return 1;
    return 0;
}

int main()
{
    int v1, v2;
    Ponto p;

    scanf("%d %d", &p.x, &p.y);
    scanf("%d %d", &v1, &v2);

    if (dentro_fora(p, v1, v2))
    {
        printf("Ponto(%d, %d) esta dentro do retangulo(%d, %d)", p.x, p.y, v1, v2);
    } else
    {
        printf("Ponto(%d, %d) nao esta dentro do retangulo(%d, %d)",  p.x, p.y, v1, v2);
    }
    
    return 0;
}
