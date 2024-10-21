#include<stdio.h>
#include<string.h>

/*
    depois de lida a risada passo para uma string apenas as vogais
    e nela analiso se a string inversa = a string normal, se for
    é engraçado.
*/

int main()
{
    char s1[100], s2[100];
    int i, j = 0, tam, isFunny;
    scanf("%s", s1);

    for (i = 0; s1[i] != '\0'; i++)
    {
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
        {
            s2[j++] = s1[i];
        }
    }

    s2[j] = '\0';
    tam = strlen(s2);
    
    for (i = 0, j = tam-1; i < tam; i++, j--)
    {
        if(s2[i] != s2[j])
        {
            isFunny = 0;
            break;
        } else isFunny = 1;
            
    }

    if (isFunny) printf("S\n");
    else printf("N\n");
    
    return 0;
}
