#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
    primeiro fiz um loop com o EOF pegando as hrs e min, dividi hrs por min para descobrir a qtd de testes
    ai armazenei os valores num vetor e fiz outra variavel para a media
    depois fiz o somatorio da formula
    e em seguida completei a formula com a raiz quadrada do somatorio / testes-1 e printei
*/
int main()
{
    double x[100000], x_avr, sum, r, qt, h, m;
    while (scanf("%lf %lf", &h, &m) != EOF)
    {
        x_avr = sum = 0;
        qt = floor(h * 60 / m);
        for (int i = 0; i < qt; i++)
        {
            scanf("%lf", &x[i]);
            x_avr += x[i];
        }
        x_avr /= qt;
        for (int i = 0; i < qt; i++)
        {
            sum += pow(x[i]-x_avr, 2.0);
        }
        r = sqrt(sum/(qt-1.0));
        printf("%.5lf\n", r);
    }
    
    return 0;
}
