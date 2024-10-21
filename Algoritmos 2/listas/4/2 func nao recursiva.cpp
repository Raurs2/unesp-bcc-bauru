#include<stdio.h>

int Fr(int i) {
    if (i > 1)
        return i + Fr(i-1);
    return 1;
}

int F(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int Fur(int i){
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return Fur(i-1) + Fur(i-2);
}

int Fu(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
    
}

int main()
{
    printf("F R = %d\nF = %d\nFu R = %d\nFu = %d", Fr(10), F(10), Fur(10), Fu(10));
    return 0;
}
