#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

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

int main(){

    printf("sequencia no it comeca na posicao 1, 2, 3...\nSequencia no Recu comeca na posicao 0, 1, 2...\n");
    printf("IT %d\n", fiboIt(11));
    printf("Recu %d\n", fiboRecu(10));

    return 0;
}    
    
/*
a) Execute a versão recursiva e não-recursiva da função Fibonacci e, examine quanto tempo
cada uma exige conforme se aumenta o valor de n.
    conforme mais vai aumentando o n, maior sera a diferanca de tempo entre o iterativo e recursivo sendo que o recursivo vai ficando cada fez mais lento
b) Conte o número de adições necessárias para calcular Fibo(n) para 0 <=n<=10, por meio
dos métodos iterativo e recursivo. Existe algum tipo de padrão?

*/