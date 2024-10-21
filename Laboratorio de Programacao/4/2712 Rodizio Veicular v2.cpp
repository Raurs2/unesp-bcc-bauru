#include <string.h> 
#include <stdio.h> 
#include <ctype.h>
/*

*/

int main(){ 
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        char placa[110];
        //scanf ("%[^\n]%*c", placa);
        //gets(placa);
        fgets(placa, 110, stdin);
        //scanf("%s", &placa);

        if (!(strlen(placa) == 9 && isupper(placa[0]) && isupper(placa[1])
        && isupper(placa[2]) && placa[3] == '-' && isdigit(placa[4])
        && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])))
            printf("FAILURE\n");
        else {
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

        }
    }

    return 0;
}