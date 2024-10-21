#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    comparei a string com o alfabeto e se as diferencas forem maiores doq 2 entao precisa de mais de uma passagem
*/

int main()
{
    int test, letras, c = 0;
    char str1[30], str2[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &test);
    for (int j = 0; j < test; j++)
    {
        scanf("%d\n", &letras);
        c = 0;
        scanf("%s", &str1);
        for (int i = 0; i < letras; i++)
        {
            if (str1[i] != str2[i])
            {
                c++;
            }
            if (c > 2)
            {
                break;
            }
        }
        if (c <= 2) printf("There are the chance.\n");
        else printf("There aren't the chance.\n");
    }
    
    return 0;
}