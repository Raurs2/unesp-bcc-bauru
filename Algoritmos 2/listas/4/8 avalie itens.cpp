#include <cstdio>
#include <cstdlib>

int fiboIt(int n)
{
    int i, fn = 1, f1 = 0, f2 = 1;
    if (n == 1) return f1;
    if (n == 2) return f2;
    for (i = 3; i <= n; i++)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

int fiboRecu(int n)
{
    if (n < 2) return n;
    return fiboRecu(n-1) + fiboRecu(n - 2);
    
}

double fat(double n)
{
    if (n == 0)
    {
        return 1;
    } else
    {
        return n * fat(n-1);
    }
}

int prod(int a, int b)
{
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        sum += b;
    }
    return sum;
}

int prodR(int a, int b)
{
    if (a == 0)
    {
        return 0;
    } else
    {
        return b + prod(a-1, b);
    }
}

int main(){
    printf("a %.0lf\n", fat(6));
    printf("b %.0lf\n", fat(9));
    printf("c %d\n", prodR(50, 3));
    printf("d %d\n", prodR(5, 4));
    printf("e %d\n", fiboRecu(9));
    printf("f %d\n", fiboRecu(10));

    return 0;
}    
    
/*
a) 6! 
b) 9!
c) 50*3 
d) 5*4
e) F(10) 
f) F(11)
Resultados
    a 720
    b 362880
    c 150
    d 20
    e 34
    f 55
*/