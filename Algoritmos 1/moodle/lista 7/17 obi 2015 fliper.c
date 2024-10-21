#include<stdio.h>
#include<math.h>

#define pi 3.14159265359

int main()
{
    int p, r;
    char c;
    scanf("%d %d", &p, &r);
    if (p == 0) c = 'C';
    else if (r == 0) c = 'B';
    else if (r == 1) c = 'A';
    printf("%c", c);
    return 0;
}
// 0 esquerda 1 direita
