#include<stdio.h>
#include<string.h>

/*
    usei a strstr para ver se tinha a sequencia no dna da bacteria
    se tinha  é resistente senao nao.
*/

int main()
{
    char d[101], s[101];

    while (scanf(" %s %s", d, s) != EOF)
	{
		if (!strstr(d, s)) printf("Nao resistente\n");
		else printf("Resistente\n");
	}
    
    return 0;
}
