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
        printf("%d\n", c);
    } while (c != ESC);
    
    return 0;
}
