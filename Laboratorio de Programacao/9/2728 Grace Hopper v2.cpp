#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
    Eu usei o strtok para separar a frase em palavras e em cada palavra vi se tem no inicio ou final uma letra
    do cobol e se tem na ordem certa imprime o grace hopper senao imprime bug
*/

int main () {
    char s[51], *word;
    int isWorking;
    while (scanf("%s", s) != EOF)
    {

        word = strtok(s, "-");

        for (int i = 0; i < 5; i++)
        {
            isWorking = 0;

            if (i == 0 && (tolower(word[0]) == 'c' || tolower(word[strlen(word)-1]) == 'c'))
                isWorking = 1;
            else if (i == 1 && (tolower(word[0]) == 'o' || tolower(word[strlen(word)-1]) == 'o'))
                isWorking = 1;
            else if (i == 2 && (tolower(word[0]) == 'b' || tolower(word[strlen(word)-1]) == 'b'))
                isWorking = 1;
            else if (i == 3 && (tolower(word[0]) == 'o' || tolower(word[strlen(word)-1]) == 'o'))
                isWorking = 1;
            else if (i == 4 && (tolower(word[0]) == 'l' || tolower(word[strlen(word)-1]) == 'l'))
                isWorking = 1;
            
            if (!isWorking) break;
            
            word = strtok(NULL, "-");
        }

        if (isWorking) printf("GRACE HOPPER\n");
        else printf("BUG\n");
    }
    
    return 0;
}