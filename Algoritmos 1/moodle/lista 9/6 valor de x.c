#include <stdio.h> 

int main() 
{
    float v[5], x;
    int i;
    v[0] = 2;
    v[1] = 4;
    v[2] = 1;
    v[3] = 3;
    v[4] = 5;
    x = v[0] + v[4];
    printf ("\n%f",x);
    x = v[1] - v[4];
    printf ("\n%f",x);
    x = v[3] * v[0] - x;
    printf ("\n%f",x);
    i = 2;
    x = v[i];
    printf ("\n%f",x);
    x = v[i] / v[(int)(v[i])];
    printf ("\n%f\n",x);
    for (i = 0; i < 5; i++)
    printf ("%f ",v[i]);
}