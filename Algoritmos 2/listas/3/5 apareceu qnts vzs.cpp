#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 30

int main()
{
    FILE *arq;

    char file_name[max], word[max];
    scanf("%s", file_name); 
    scanf("%s", word);
    
    if ((arq = fopen(file_name, "rt")) == NULL)
    {
        printf("ARQUIVO N ABERTO\n");
        exit(1);
    }
    
    char word_match[max];
    int i = 0;
    while (fscanf(arq, "%s", word_match) != EOF)
    {
        if (!strcmp(word, word_match)) i++;
    }
    fclose(arq);
    
    printf("A palavra %s apareceu %d vezes\n", word, i);
    
    return 0;
}
