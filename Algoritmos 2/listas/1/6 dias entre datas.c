#include <stdio.h>
#include <math.h>

typedef struct 
{
    int dia, mes, ano;
} dma;

int dias_entre(dma d[])
{
    int ano = abs((d[1].ano - d[0].ano) * 365);
    int mes = abs((d[1].mes - d[0].mes)) * 30;
    int dia = abs((d[1].dia - d[0].dia));
    
    return dia + mes + ano;
}

int main()
{
    dma d[2];
    int i;

    for ( i = 0; i < 2; i++)
    {
        scanf("%d %d %d", &d[i].dia, &d[i].mes, &d[i].ano);
    }
    
    i = dias_entre(d);
    printf("%d", i);
    
    return 0;
}
