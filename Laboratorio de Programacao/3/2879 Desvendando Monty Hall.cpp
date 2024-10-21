#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
    esse foi mais dificil entender do que fazer, mas depois de pensar entendi que como ele sempre escolhe inicialmente e porta 1, mas sempre troca de porta depois do apresentador 
    revelar o bode então a porta um nunca sera selecionada pelo jogador, portanto se o premio estiver la ele nunca ganhara, mas se o premio não estiver na porta 1, ele sempre
    ganhara pois o apresentador abriu a outra porta que tinha o bode entao so resta a porta do carro.
    portanto so fiz um if para se a porta do premio for diferente de 1 ele ganha.
*/
int main()
{
    int n, r, win = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &r);
        if (r != 1) win++;
    }
    printf("%d\n", win);
    
    return 0;
}
