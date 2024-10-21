#include <stdio.h>
#include <math.h>
int main() {
    int i, idade, peso, altura, idadeCount = 0, idadeMedia = 0, alturaMedia = 0, pesoMaior = 0, j, idadeTotal = 0, alturaTotal = 0;
    float pesoPorc;

    for ( i = 1; i <= 5; i++)
    {
        for ( j = 1; j <= 11; j++)
        {
            printf("Idade, Peso, Altura");
            scanf("%d %d %d", &idade, &peso, &altura);
            if (idade < 18)
            {
                idadeCount += 1;
            }
            if (peso > 80)
            {
                pesoMaior += 1;
            }
            idadeTotal += idade;
            alturaTotal += altura;
        }
        idadeMedia = idadeTotal / 11;
        idadeTotal = 0;
        printf("Media idade time %d: %d\n", i, idadeMedia);
    }
    alturaMedia = alturaTotal / 55;
    pesoPorc = pesoMaior * 100 / 55;
    printf("Menor 18: %d\nMedia Altura total: %d\n%% > 80kg %d%%\n", idadeCount, alturaMedia, pesoMaior);
    return 0;
}