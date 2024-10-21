#include<stdio.h>
#include<ctype.h>
#include<conio.h>

#define ESC 27

int main()
{
    int a;
    scanf("%d", &a);
    if (a % 400 == 0) printf("%d bissexto\n", a);
    else if (a % 4 == 0 && a % 100 != 0) printf("%d bissexto\n", a);
    return 0;
}
