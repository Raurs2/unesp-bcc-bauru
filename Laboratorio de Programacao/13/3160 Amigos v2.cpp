#include <stdio.h>
#include <string.h>

/*
    se nao indica um nome eu apenas concateno no final da lista a nova lista, porem se tem um nome indicado
    uso o strtok para separar a lista e adiciono a nova lista quando aparecer o nome.
*/

int main ()
{
    char *Token, oldList[2000], newList[2000], name[100], updatedList[4000];

    fgets(oldList, sizeof(oldList), stdin);
    oldList[strlen(oldList) - 1] = '\0';

    fgets(newList, sizeof(newList), stdin);
    newList[strlen(newList) - 1] = '\0';

    scanf("%s", &name);

    if(!strcmp(name, "nao"))
    {
        strcat(updatedList, oldList);
        strcat(updatedList, " ");
        strcat(updatedList, newList);
    }
    else
    {
        Token = strtok(oldList, " ");
        while(Token != NULL)
        {
            if(strcmp(Token, name))
                strcat(updatedList, Token);
            else
            {
                strcat(updatedList, newList);
                strcat(updatedList, " ");
                strcat(updatedList, Token);
            }
            strcat(updatedList, " ");
            Token = strtok(NULL, " ");
        }
    }

    if(strcmp(name, "nao"))
        updatedList[strlen(updatedList) - 1] = '\0';

    printf("%s\n", updatedList);
    return 0;
}