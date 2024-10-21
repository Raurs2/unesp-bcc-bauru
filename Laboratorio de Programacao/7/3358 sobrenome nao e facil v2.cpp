#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
    eu fui lendo as consoantes seguidas, se vinha vogal zerava a consoantes seguidas e se
    a consoante seguida fosse maior q 2 eu printava como nao eh facil senao printava eh facil
*/
int main()
{
    int n, conso, is;
    char name[100], c;
    scanf("%d", &n);
    getc(stdin);
    for (int i = 0; i < n; i++)
    {
        conso = 0;
        is = 0;
        scanf("%s", name);
        for (int j = 0; j < strlen(name); j++)
        {
            c = name[j];
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
            {
                conso = 0;
            } else if (tolower(c) >= 'a' && tolower(c) <= 'z')
            {
                conso++;
            }
            if (conso > 2) is = 1;
        }
        if (is) printf("%s nao eh facil\n", name);
        else printf("%s eh facil\n", name);
        //printf("\n%d\n", c);
    }
        
    return 0;
}
