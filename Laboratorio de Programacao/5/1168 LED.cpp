#include <cstdio>
#include <cstdlib>
#include <cstring>

// usei os vet que vc pediu para usar, assim peguei a qtd de leds em cada numero e somei num tot de leds

int main()
{
    int vetConverte[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // vetor indice: digito; valor armazenado: numero de LEDs
    char numero[101];  // vetor de caracteres para armazenar uma cadeia de caracteres que contém o número a ser mostrado nos LEDs
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &numero);
        int leds = 0;
        for (int j = 0; j < strlen(numero); j++)
        {
            leds += vetConverte[numero[j]-'0'];
        }
        printf("%d leds\n", leds);
    }

    return 0;
}
