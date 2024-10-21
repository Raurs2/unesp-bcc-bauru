
#include<stdio.h>

void sierpinskiTriang(int n)
{
    for (int y = n - 1; y >= 0; y--)
    {
 
        for (int i = 0; i < y; i++)
        {
            printf(" ");
        }
 
        for (int x = 0; x + y < n; x++)
        {

        if(x & y)
            printf("  ");
        else
            printf(" *");
        }
 
        printf("\n");
    }
}
 

int main()
{
    int n = 16;

    sierpinskiTriang(n);
 
    return 0;
}