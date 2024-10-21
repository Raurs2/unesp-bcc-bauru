#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
    usei uma comparacao invertida e armazenei a maior em uma variavel, pensei o seguinte,
    primeiro ele planta a maior e depois vai plantando as demais, conforme isso as que foram
    primeiras plantadas começaram a madurar, como queremos o dia que todas estao maduras, eu vou decrementando
    o maior conforme cada "muda plantada" e se a nova muda que ele plantou é a maior, entao ela assume a variavel
    depois de plantadas todas, eu conto os n dias que levou para plantar + os n dias que faltam para maior muda crescer + 1 ja que
    a festa é no dia depois de todas madurarem.
*/

int funcComparacaoInvertida(const void *pv1, const void *pv2) {
  int v1 = *(int *)pv1;
  int v2 = *(int *)pv2;
  return v2 - v1;
}

int main () {
    int n, maior;
    scanf("%d", &n);
    
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    
    qsort(v, n, sizeof(v[0]), funcComparacaoInvertida);
    
    maior = v[0];
    for (int i = 0; i < n; i++)
    {
        maior--;
        if (v[i] > maior) maior = v[i];
    }
    printf("%d\n", n + maior + 1);
    
    return 0;
}