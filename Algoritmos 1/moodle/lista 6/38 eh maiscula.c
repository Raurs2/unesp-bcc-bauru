#include<stdio.h>
#include<ctype.h>
#include<conio.h>

#define ESC 27

int main()
{
    char c;
    do
    {
        c = getch();
        if (islower(c)) c = toupper(c);
        putchar(c);
    } while (c != ESC);
    
    return 0;
}
