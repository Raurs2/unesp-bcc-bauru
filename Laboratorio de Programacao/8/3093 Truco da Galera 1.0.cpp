#include<stdio.h>
#include<string.h>

//fiz um for pra testar se q j k a se encontram no baralho se sim ele ganha

int main()
{
    int n, win = 0, q, jj, k, a;
    scanf("%d", &n);
    getchar();
    char s[1010];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);

        q = jj = k = a = 0;
        for (int j = 0; j < strlen(s); j++)
        {
            if (s[j] == 'Q') q = 1;
            if (s[j] == 'J') jj = 1;
            if (s[j] == 'K') k = 1;
            if (s[j] == 'A') a = 1;
        }
        
        win = q && jj && k && a;

        if (win) printf("Aaah muleke\n");
        else printf("Ooo raca viu\n");
    }
    
    return 0;
}
