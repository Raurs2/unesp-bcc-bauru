#include <stdio.h>
#include <math.h>

#define MAX 10000

int main() {
    int anoAtual, nextAno, lastAno, i;
    scanf("%d", &anoAtual);
    lastAno = 1986;
    for (i = lastAno; i < MAX; i += 76)
    {
        nextAno = i + 76;

        if (nextAno > anoAtual)
        {
            printf("%d", nextAno);
            break;
        }
    }
    return 0;
}