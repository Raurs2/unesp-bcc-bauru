#include <stdio.h>
#include <math.h>
int main() {
    float salMin, hrsTrab, dependFuncio, hrsExtra, salBruto, imposto, salLiq, grat;

    scanf("%f %f %f %f", &salMin, &hrsTrab, &dependFuncio, &hrsExtra);
    
    salBruto = (hrsTrab * 0.2 * salMin) + (32 * dependFuncio) + (hrsExtra * 1.7 * salMin);

    if (salBruto >= 900 && salBruto <= 1400)
    {
        imposto = salBruto * 0.1;
    } else if (salBruto > 1400)
    {
        imposto = salBruto * 0.2;
    }

    salLiq = salBruto - imposto;

    if (salLiq <= 950)
    {
        grat = 100;
        salLiq += 100;
    } else {
        grat = 50;
        salLiq += 50;
    }
    
    printf("BRUTO: %.2f\nIMPOSTO: %.2f\nGRATIFICACAO: %.2f\nLIQUIDO: %.2f\n", salBruto, imposto, grat, salLiq);

    return 0;
}