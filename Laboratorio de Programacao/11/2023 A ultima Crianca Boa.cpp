#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    usei o qsort e funcoes auxiliares para ordernar o vetor de nomes e assim
    descobrir a ultima criança boa
*/

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}

int compare(const void *a, const void *b)
{
    const char *s1 = (const char *) a;
    const char *s2 = (const char *) b;

    return strcicmp(s2, s1);
}


int main()
{
    char nomes[1000][101];
    int i = 0;

    while (fgets(nomes[i], 101, stdin) != NULL)
        i++;

    qsort(nomes, i, 101, compare);

    printf("%s", nomes[0]);
    
    return 0;
}
