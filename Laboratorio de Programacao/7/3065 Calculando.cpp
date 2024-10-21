#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define max 1000
/*
    para calcular eu separei a expressao string em dois vetores int um para os numeros e outro para os sinais
    depois disso coloquei o primeiro numero ja no resultado e os proximos fui adicionando ou subtraindo dependendo se o
    sinal era 1 para mais ou 0 para menos.
*/
int main()
{
    int op, test = 1, result, n[max], i = 0, sinal[max], j = 0;
    char exp[max], *token;

    do
    {
        i = j = 0;
        scanf("%d", &op);
        if (op == 0) break;
        scanf("%s", exp);
        
        for (int k = 0; k < strlen(exp); k++)
        {
            if (exp[k] == '+')
            {
                sinal[j] = 1;
                j++;
            } else if (exp[k] == '-')
            {
                sinal[j] = 0;
                j++;
            }
        }

        token = strtok(exp, "+-");
        n[i] = atoi(token);
        do
        {
            i++;
            token = strtok(NULL, "+-");
            if (token) n[i] = atoi(token);
        } while (token);
        
        
        
        result = n[0];
        for (int i = 0; i < op-1; i++)
        {
            if (sinal[i]) result += n[i+1];
            else result -= n[i+1];
        }
        
        printf("Teste %d\n%d\n\n", test, result);
        test++;
    } while (op != 0);
    
    return 0;
}
