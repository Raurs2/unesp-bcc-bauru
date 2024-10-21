#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
    
*/

int main () {
    char s[101];
    int isC, isO, isB, isO2, isL;

    while (scanf("%s", s) != EOF)
    {
        isC = isO = isB = isO2 = isL = 0;

        for (int i = 0; i < strlen(s); i++)
        {
            if (!isC && tolower(s[i]) == 'c') isC = 1;
            else if (!isO && tolower(s[i]) == 'o') isO = 1;
            else if (!isB && tolower(s[i]) == 'b') isB = 1;
            else if (!isO2 && tolower(s[i]) == 'o') isO2 = 1;
            else if (!isL && tolower(s[i]) == 'l') isL = 1;
        }

        if (isC && isO && isB && isO2 && isL) printf("GRACE HOPPER\n");
        else printf("BUG\n");
    }
    
    return 0;
}