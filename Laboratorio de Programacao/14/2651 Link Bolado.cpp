#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/*
    depois de pegar o nome fiz um for duplo para testar de 5 em 5 letras se formava a palavra zelda
*/

int main()
{
    char s[100001], zelda[6];
    int iszelda = 0, k;

    fgets(s, sizeof(s), stdin);
    int len = strlen(s);

    for(int i = 0; (i < len - 5) && (!iszelda); i++)
    {
        k = 0;
        
        for(int j = i; j < i + 5; j++)
        {
            zelda[k] = tolower(s[j]);
            k++;
        }
        
        zelda[5] = '\0';

        if(!strcmp("zelda", zelda)) iszelda = 1;
    }
    
    if (iszelda) printf("Link Bolado\n");
    else printf("Link Tranquilo\n");
    
    return 0;
}
