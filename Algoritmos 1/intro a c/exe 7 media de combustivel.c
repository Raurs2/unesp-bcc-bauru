#include<stdio.h>
int main()
{
    float kmRodado, gasolinaGasta, media;
    printf("kmRodado e gasolinaGasta: ");
    scanf("%f %f", &kmRodado, &gasolinaGasta);
    media = kmRodado / gasolinaGasta;
    printf("Media: %.2fkm/l", media);
    return 0;
}
