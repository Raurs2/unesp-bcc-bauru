#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

/*
    Eu li a string de traz pra frente e se for minuscula o char eu printo
*/

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char cod[1000];
        scanf("%s", &cod);
        for (int j = strlen(cod)-1; j >= 0; j--)
        {
            if (islower(cod[j]))
            {
                printf("%c", cod[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
