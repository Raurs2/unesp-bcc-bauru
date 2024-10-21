#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, area, potencia, potResidencia = 0;
    int classe, comodo, lampadas, i = 0, lampResidencia = 0;
    do
    {
        scanf("%d %lf %lf", &classe, &x, &y);

        if (classe >= 1 && classe <= 3)
        {
            area = x * y;
            if (classe == 1)
            {
                potencia = 15 * area;
            } else if (classe == 2)
            {
                potencia = 18 * area;
            } else if (classe == 3)
            {
                potencia = 20 * area;
            }
            lampadas = potencia / 60;
            potResidencia += potencia;
            lampResidencia += lampadas;
            
            printf("Comodo %d\nArea: %.2lf Potencia: %.2lf Lampadas: %d\n\n", i++, area, potencia, lampadas);
        }
    } while (classe >= 1 && classe <= 3);
    
    printf("Residencia\nPotencia: %.2lf Lampadas: %d\n", potResidencia, lampResidencia);
    return 0;
}