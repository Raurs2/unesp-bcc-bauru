#include <stdio.h>
#include <math.h>

int main() {
    int n, sum = 0, i = 0, maior, menor, even = 0;
    float avr, avrOdd = 0, porEven;
    
    do
    {
        scanf("%d", &n);
        
        sum += n;

        if (i == 0)
        {
            maior = n;
            menor = n;
        }

        if (n > maior) maior = n;
        if (n < menor) menor = n;

        if (n % 2 == 0) even++;
        else avrOdd += n;
        
        i++;
    } while (n != 100000);

    avr = (float)sum / i;
    avrOdd /= (float)(i - even);
    porEven = even * 100.0 / i;
    
    printf("Soma: %d\nN Digitados: %d\nMedia total: %.2f\nMaior: %d\nMenor: %d\nMedia impar: %.2f\nPares: %.2f%%", sum, i, avr, maior, menor, avrOdd, porEven);
    
    return 0;    
}