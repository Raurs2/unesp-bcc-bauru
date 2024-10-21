#include<stdio.h>
#include<ctype.h>

#define max 2000

/*

*/

int main()
{
    int n, lin, col, m[max][max];
    char words[4][50];

    scanf("%d %d %d\n", &n, &lin, &col);
    for (int i = 0; i < n; i++)
        scanf("%s\n", &words[i]);
    for (int i = 0; i < lin; i++)
    {
            scanf("%s", &m[i]);
    }
    
    
    
    return 0;
}
