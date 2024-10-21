#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
    fiz um loop com o EOF, dentro fiz uma formula para calcular o atraso maximo, coloquei o modulo para sempre sair positivo o resultado
    ainda coloquei uma condicao pra caso o valor for menor ou igual a 7:00 para zerar o atraso, depois printei.
*/
int main()
{
    int h, m;
    while (scanf("%d:%d", &h, &m) != EOF)
    {
        int r = abs(((8 - h) * 60 - m) - 60);
        if (h < 7 || h == 7 && m == 00) r = 0;
        printf("Atraso maximo: %d\n", r);
    }
    
    return 0;
}
