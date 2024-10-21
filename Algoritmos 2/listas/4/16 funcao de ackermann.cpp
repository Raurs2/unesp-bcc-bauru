#include <cstdio>
#include <cstdlib>

double a(double m, double n)
{
    if (m == 0)
    {
        return n + 1;
    } else if (n == 0)
    {
        return a(m-1, 1);
    } else
    {
        return a(m-1, a(m, n-1));
    }
}

int main(){
    double m, n;

    while (scanf("%lf %lf", &m, &n) != EOF)
        printf("R: %.0lf\n", a(m, n));
    
    return 0;
}    

/*
a) Usando a definição anterior, demonstre que a(2,2) é igual a 7.
    executei o programa e 2 2 resultou em 7
b) Prove que a(m,n) está definido para todos os inteiros não-negativos m e n.
    esta definido pra todo int nao negativo pois a condicao base de parada eh m = 0, a funcao percorrera todos os int m ate chegar no m = 0.
c) Você consegue descobrir um método iterativo para calcular a(m,n)?
    não consigo.
*/