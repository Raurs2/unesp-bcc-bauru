#include <cstdio>
#include <cstdlib>
/*
    fiz com struct armazenando nivel e posicao, depois comparei os niveis pegando o maior e segundo maior nivel e mostrei a pos do segundo maior nivel 
*/
typedef struct{
    int nivel;
    int pos;
} Suspeito;

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
        Suspeito suspeitos[n], mais_suspeitos[2];
        if (n == 0) break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &suspeitos[i].nivel);
            suspeitos[i].pos = 1+i;
        }

        mais_suspeitos[0].nivel = 0;
        mais_suspeitos[1].nivel = 0;
        for (int i = 0; i < n; i++)
        {
            if (suspeitos[i].nivel > mais_suspeitos[0].nivel)
            {
                mais_suspeitos[0] = suspeitos[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (suspeitos[i].nivel > mais_suspeitos[1].nivel && suspeitos[i].nivel < mais_suspeitos[0].nivel)
            {
                mais_suspeitos[1] = suspeitos[i];  
            }
        }
        
        printf("%d\n", mais_suspeitos[1].pos);
    } while (1);
    
    return 0;
}
