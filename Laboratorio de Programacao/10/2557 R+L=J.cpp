#include<stdio.h>

/*
    
*/

int main()
{
    char r[100], l[100], j[100];
    int n1, n2, n3;
    
    while (scanf("%s+%s=%s", &r, &l, &j) != EOF)
    {
        if (r[0] == 'R')
        {
            n1 = l - '0';
            n2 = j - '0';
            n3 = n2 - n1;
        } else if (l[0] == 'L')
        {
            n1 = r - '0';
            n2 = j - '0';
            n3 = n2 - n1;
        } else if (j[0] == 'J')
        {
            n1 = r - '0';
            n2 = l - '0';
            n3 = n2 + n1;
        }
        printf("%d\n", n3);
        getchar();
    }
    
    return 0;
}