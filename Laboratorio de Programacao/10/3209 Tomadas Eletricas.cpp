#include<stdio.h>

/*
    peguei os valores das extensoes e somei subtraindo um no final adicionei um pois a ultima extensao
    tem todas as entradas vagas.
*/

int main()
{
    int n, k, o, sum;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        sum = 0;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &o);
            sum += o - 1;
        }
        sum++;
        printf("%d\n", sum);
    }
    
    return 0;
}