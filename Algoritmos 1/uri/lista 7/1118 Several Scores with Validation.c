#include <stdio.h>
#include <math.h>
/*
    primeiro fiz um loop para rodar o programa enquanto n != 2 depois um loop para pegar e validar as notas dentro do loop fiz varias condicionais para testar a validade de cada nota separadamente
    e quando as duas são validas coloquei um break para sair do loop, saindo do loop ele calcula a media e recebe se quer sair do programa ou continuar em outro loop onde vai rodar ate ser 1 ou 2.
*/
int main() {
    double n1, n2, avr = 0, x = -1, y = -1;
    int n;
    do
    {
        do
        {
            if (x != -1 && y != -1) break;
            scanf("%lf %lf", &n1, &n2);
            if (x > 0)
            {
                if (n1 < 0 || n1 > 10) {
                printf("nota invalida\n");
                
                } else y = n1;
            }
            if (y > 0)
            {
                if (n2 < 0 || n2 > 10) {
                printf("nota invalida\n");
                
                } else x = n2;
            }
            if (x != -1 && y != -1) break;
            if (n1 < 0 || n1 > 10) {
                printf("nota invalida\n");
                
            } else x = n1;
            if (n2 < 0 || n2 > 10) {
                printf("nota invalida\n");
                
            } else y = n2;
        } while (x < 0 || y < 0);
        printf("media = %.2lf\n", (x+y)/2);
        do
        {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &n);
        } while (n != 1 && n != 2);
        x = -1;
        y = -1;
    } while (n != 2);
    return 0;    
}