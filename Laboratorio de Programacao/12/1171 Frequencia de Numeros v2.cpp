#include<stdio.h>

/*
    fiz um vetor contador com indices de 0 a 2000, assim ele armazena 
    a quantidade de vezes que aparece o numero do indice.
*/

int main()
{
    int n, x[2001] = {}, d;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        x[d]++;
    }    
    
    for (int i = 0; i < 2001; i++)
    {
        if (x[i] > 0)
            printf("%d aparece %d vez(es)\n", i, x[i]);
    }

    return 0;
}
