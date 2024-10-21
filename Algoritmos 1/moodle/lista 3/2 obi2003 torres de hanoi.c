#include <stdio.h>
#include <math.h>

void move_disco(int d, char ori, char dest, char aux) {
    if (d ==1) {
        printf("Mover disco %d de %c para %c", d, ori, dest);
    } else {
        move_disco(d-1, ori, aux, dest);
        printf("Mover disco %d de %c para %c", d, ori, dest);
        move_disco(d-1, aux, dest, ori);
    }
    
}

int main() {
    int disco =1, movimentos, i = 1;
    //move_disco(disco, 'A', 'C', 'B');
    while (disco != 0)
    {
        scanf("%d", &disco);
        movimentos = (int)pow(2, (double)disco) - 1;
        printf("Teste %d\n%d\n\n", i++, movimentos);
    }
    

    return 0;
}