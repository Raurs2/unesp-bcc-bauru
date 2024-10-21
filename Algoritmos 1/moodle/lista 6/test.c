#include <stdio.h>
int main() {
    int a, b, total, soma, termo, i;
    scanf ("%d %d",&a,&b);
    printf ("(%d,%d)",a,b);
    total = soma = 0;
    while (a){
        total++;
        termo = 1;
        for (i = 1; i <= b; i++)
            termo *= a;
        printf ("\nResp = %d",termo);
        soma += termo;
        printf ("\nSoma = %d\n",soma);
        scanf ("%d %d",&a,&b);
        printf ("\n\n(%d,%d)",a,b);
    }
    printf ("\n\nTotal de pares: %d",total);
}