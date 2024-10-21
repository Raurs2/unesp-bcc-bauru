#include <stdio.h>

int main () {
    int diaHj, mesHj, anoHj, dia, mes, ano, viveu;
    printf("Data atual:\n");
    scanf("%d %d %d", &diaHj, &mesHj, &anoHj);
    printf("\nData de nascimento:\n");
    scanf("%d %d %d", &dia, &mes, &ano);
    viveu = (anoHj * 365 + mesHj * 30 + diaHj) - (ano * 365 + mes * 30 + dia); 
    printf("\nViveu: %d Dias\n", viveu);
}