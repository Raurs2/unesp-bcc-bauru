#include <string.h> 
#include <stdio.h> 

/*
    fiz um for para verificar se as letras sao maisculas e outro se sao numeros depois verifiquei se tinha o tracinho
    se tudo isso é verdade entao ele vai printa o dia dependedendo do final da placa senao
    printa a mensagem de erro
*/

char placa[101];

int main(){ 
    int n;
    scanf("%d", &n);
    fgets(placa, 101, stdin);
    
    for (int i = 0; i < n; i++)
    {
        //gets(placa);
        fgets(placa, 101, stdin);

        int sum1 = 0;
        for (int j = 0; j < 3; j++)
        {
            sum1 += placa[j] >= 'A' && placa [j] <= 'Z';
        }
        
        int sum2 = 0;
        for (int j = 4; j < 8; j++)
        {
            sum2 += placa[j] >= '0' && placa [j] <= '9';
        }

        if (sum1 == 3 && sum2 == 4 && placa[3] == '-' && strlen(placa) == 9)
        {
            if (placa[7] == '1' || placa[7] == '2')
            {
                printf("MONDAY\n");
            } else if (placa[7] == '3' || placa[7] == '4')
            {
                printf("TUESDAY\n");
            } else if (placa[7] == '5' || placa[7] == '6')
            {
                printf("WEDNESDAY\n");
            } else if (placa[7] == '7' || placa[7] == '8')
            {
                printf("THURSDAY\n");
            } else if (placa[7] == '9' || placa[7] == '0')
            {
                printf("FRIDAY\n");
            } 

        } else printf("FAILURE\n");
    }

    return 0;
}