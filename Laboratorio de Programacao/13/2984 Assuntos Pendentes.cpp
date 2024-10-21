#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    marquei assuntos abertos e finalizados depois percorri a string para ver se ainda tinha algum assunto aberto
*/

int main()
{
    int len, x = 0;
    char s[100001];
    scanf("%s", &s);
    len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '(') continue;

        for (int j = i + 1; j < len; j++)
        {
            if (s[j] == ')')
            {
                s[i] = 'x';
                s[j] = 'x';
                break;
            }
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(') x++;
    }
    
    if (x != 0) printf("Ainda temos %d assunto(s) pendente(s)!\n", x);
    else printf("Partiu RU!\n");
    
    return 0;
}