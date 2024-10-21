#include<stdio.h>
int main()
{
    float yearsSmoking, cigarDaily, cigarPrice, tot;
    printf("informe o preco do cigarro, anos fumando e quantos cigar por dia\n");
    scanf("%f %f %f", &cigarPrice, &yearsSmoking, &cigarDaily);
    tot = (yearsSmoking * 365) * ((cigarDaily * cigarPrice) / 20);
    printf("Dinheiro gasto em cigar: %.2f", tot);
    return 0;
}
