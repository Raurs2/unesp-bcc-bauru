#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
    apenas vi um relogio e seus angulos e dividi 1 min = 6 graus e 1 hr = 30 graus
*/

int main () {
    int h, m;

    while (scanf("%d %d", &h, &m) != EOF)
    {
        h /= 30;
        m /= 6;
        printf("%02d:%02d\n", h, m);
    }
    
    return 0;
}