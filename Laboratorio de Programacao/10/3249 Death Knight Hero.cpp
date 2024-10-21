#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    usei o strtok pra ver se tinha o CD, se n tem ele vence.
*/

int main() {
    int n, vence = 0;
    char s[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &s);

        if (strstr(s, "CD") == NULL)
        {
            vence++;
        }
        
    }
    printf("%d\n", vence);

    return 0;
}