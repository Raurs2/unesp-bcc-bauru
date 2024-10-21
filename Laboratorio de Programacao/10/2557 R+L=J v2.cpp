#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    li uma string separei ela num vetor int usando strtok
    e depois dependendo de qual tinha letra fiz a conta e 
    mostrei o resultado
*/

int main() {
    char lin[100];
    char *token;
    int n[3], r;
    
    while (fgets(lin, 100, stdin) != NULL)
    {
        
        r = 2;
        token = strtok(lin, "+");
        if (token[0] != 'R')
            n[0] = atoi(token);
        else
        {
            n[0] = 0;
            r = 0;
        }

        token = strtok(NULL, "=");
        if (token[0] != 'L')
            n[1] = atoi(token);
        else
        {
            n[1] = 0;
            r = 1;
        }

        token = strtok(NULL, "\n");
        if (token[0] != 'J')
            n[2] = atoi(token);
        else
            n[2] = 0;
        
        if (!r)
            printf("%d\n", n[2] - n[1]);
        else if (r == 1)
            printf("%d\n", n[2] - n[0]);
        else
            printf("%d\n", n[0] + n[1]);
    }

    return 0;
}