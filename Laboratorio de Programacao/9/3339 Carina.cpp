#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
    fiz o numero multiplicado por ele mesmo e caso esteja dentro do intervalo entao 
    o contador aumenta se estourar o intervalo ele sai do for.
*/

int main () {
    int n, c;
    int l, r;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        c = 0;
        scanf("%d %d", &l, &r);
        for (int j = 0; j < r; j++)
        {
            if (j * j >= l && j * j <= r) c++;
            else if (j * j > r) break;
        }
        
        printf("%d\n", c);
    }
    
    return 0;
}