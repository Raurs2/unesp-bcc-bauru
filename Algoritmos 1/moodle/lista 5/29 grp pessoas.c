#include <stdio.h>
#include <math.h>

int main()
{
    float altura, media = 0, menor, maior;
    int sexo, i, homens = 0;

    for (i = 1; i <= 12; i++)
    {
        scanf("%d %f", &sexo, &altura);

        if (i == 1)
        {
            menor = altura;
            maior = altura;
        }

        if (altura > maior)
        {
            maior = altura;
        }

        if (altura < menor)
        {
            menor = altura;
        }

        if (sexo == 2)
        {
            media += altura;
        }

        if (sexo == 1)
        {
            homens++;
        }
    }

    printf("Maior: %.2f\nMenor: %.2f\nMedia: %.2f\nHomens: %d\npercentual: %.2f", maior, menor, media / 12, homens, homens * 100.0 / 12.0);
    
    return 0;
}