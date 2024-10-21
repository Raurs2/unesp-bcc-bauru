#include <stdio.h>
#include <math.h>

int main() {
    int goalsInter = 0, goalsGremio = 0, n, i = 0, vicInter = 0, vicGremio = 0, empate = 0;
    do
    {
            scanf("%d %d", &goalsInter, &goalsGremio);
            i++;
            if (goalsInter > goalsGremio) vicInter++;
            if (goalsGremio > goalsInter) vicGremio++;
            if (goalsGremio == goalsInter) empate++;
        do
        {
            printf("Novo grenal (1-sim 2-nao)\n");
            scanf("%d", &n);
        } while (n != 1 && n != 2);
    } while (n != 2);
    printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n", i, vicInter, vicGremio, empate);
    if (vicInter > vicGremio) printf("Inter venceu mais\n");
    else if (vicGremio > vicInter) printf("Gremio venceu mais\n");
    else printf("Não houve vencedor\n");

    return 0;    
}