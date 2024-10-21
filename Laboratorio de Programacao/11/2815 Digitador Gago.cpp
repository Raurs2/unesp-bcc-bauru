#include<stdio.h>
#include<string.h>

/*
    li a linha depois fiz uma matriz dividindo a frase em palavras com strtok e 
    por fim comparei as inicias das palavras se tinha repetição eu não impria a 
    repetição
*/

int main()
{
    char s[16000], *text, words[2000][20];
    scanf("%[^\n]", s);

    int i = 0;
    text = strtok(s, " ");
    strcpy(words[i++], text);
    do
    {
        text = strtok(NULL, " ");
        if(text) strcpy(words[i++], text);
    
    } while (text);
    int islast = 0;
    for (int j = 0; j < i; j++)
    {
        islast = j == i-1;
        if (strlen(words[j]) >= 4)
        {
            if (words[j][0] == words[j][2] && words[j][1] == words[j][3])
            {
                printf("%s", &words[j][2]);
            } else
            {
                printf("%s", words[j]);
            } 
            
        } else
        {
            printf("%s", words[j]);
        }
        if (!islast)
        {
            printf(" ");
        }
        
    }
    printf("\n");

    return 0;
}
