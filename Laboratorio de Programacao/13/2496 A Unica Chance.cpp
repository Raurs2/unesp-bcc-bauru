#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int test, letras, c = 0;
    char str1[30], str2[30];
    scanf("%d", &test);
    scanf("%d\n", &letras);
    for (int j = 0; j < test; j++)
    {
        scanf("%s", &str1);
        printf("a = %s str2 = %s", str1, str2);
        strcpy(str2, str1);
        qsort(str2, 5, sizeof(str2), cmpfunc);
        printf("a = %s str2 = %s", str1, str2);
        for (int i = 0; i < letras; i++)
        {
            if (str1[i] != str2[i])
            {
                c++;
            }
            if (c > 1)
            {
                printf("There aren't the chance.\n");
                exit(0);
            }
        }
        printf("There are the chance.\n");
    }
    
    return 0;
}