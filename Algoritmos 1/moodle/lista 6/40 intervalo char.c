#include<stdio.h>
#include<ctype.h>
#include<conio.h>

#define ESC 27

int main()
{
    int n;
    char a, b;
    do
    {
        a = getch();
        if (a == ESC) break;
        if (isupper(a)) a = tolower(a);
        b = getch();
        if (isupper(b)) b = tolower(b);
        n = (int)(b) - (int)(a) - 1;
        printf("c entre %c e %c = %d\n", a, b, n);
    } while (a != ESC);
    
    return 0;
}
