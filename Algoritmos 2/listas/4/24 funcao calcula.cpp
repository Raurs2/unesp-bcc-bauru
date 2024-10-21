#include <cstdio>
#include <cstdlib>


// calcula somatorio de numeros de 0 ate n
int funcR(int n){
    if (n == 0)
        return 0;
    return n + funcR(n-1);
}

int funcI(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main(){
    int n = 3;
    printf("%d\n", funcR(n));
    printf("%d\n", funcI(n));
    return 0;
}    
