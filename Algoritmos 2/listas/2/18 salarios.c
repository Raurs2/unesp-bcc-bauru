#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    FILE *bruto, *desc, *liq;
    double sal_bruto, sal_liq, sal_desc;

    if ((bruto = fopen("salbruto.bin", "rb")) == NULL)
    {
        printf("Erro de abertura 1");
        exit(1);
    }
    
    if ((desc = fopen("desc.bin", "rb")) == NULL)
    {
        printf("Erro de abertura 2");
        exit(1);
    }
    
    if ((liq = fopen("salliq.txt", "w")) == NULL)
    {
        printf("Erro de abertura 3");
        exit(1);
    }
    
    while (fread(&sal_bruto, sizeof(double), 1, bruto) == 1 && fread(&sal_desc, sizeof(double), 1, desc) == 1)
    {
        sal_liq = sal_bruto - sal_desc;
        fwrite(&sal_liq, sizeof(double), 1, liq);
    }
    fclose(liq);
    fclose(desc);
    fclose(bruto);
    
    return 0;
}
