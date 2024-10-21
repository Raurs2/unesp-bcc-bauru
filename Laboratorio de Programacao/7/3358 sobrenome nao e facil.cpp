#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int n, c, is;
    char name[100];
    scanf("%d", &n);
    getc(stdin);
    for (int i = 0; i < n; i++)
    {
        c = 0;
        is = 0;
        scanf("%s", name);
        for (int j = 0; j < strlen(name); j++)
        {
            if ((tolower(name[j]) >= 'a' && tolower(name[j]) <= 'z') && (tolower(name[j]) != 'a' || tolower(name[j]) != 'e' || tolower(name[j]) != 'i' || tolower(name[j]) != 'o' || tolower(name[j]) != 'u'))
            {
                c++;
                if (c >= 3) is = 1;
            }
            else c = 0;
        }
        if (is) printf("%s nao eh facil\n", name);
        else printf("%s eh facil\n", name);
        //printf("\n%d\n", c);
    }
        
    return 0;
}
