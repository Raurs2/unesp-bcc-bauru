#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20

void dataSla(int d, int m, int a, char dia[], char mes[], char ano[], char data[]) {
    switch (m) {
        case 1:
            strcpy(mes, "Janeiro");
            break;
        case 2:
            strcpy(mes, "Fevereiro");
            break;
        case 3:
            strcpy(mes, "Marco");
            break;
        case 4:
            strcpy(mes, "Abril");
            break;
        case 5:
            strcpy(mes, "Maio");
            break;
        case 6:
            strcpy(mes, "Junho");
            break;
        case 7:
            strcpy(mes, "Julho");
            break;
        case 8:
            strcpy(mes, "Agosto");
            break;
        case 9:
            strcpy(mes, "Setembro");
            break;
        case 10:
            strcpy(mes, "Outubro");
            break;
        case 11:
            strcpy(mes, "Novembro");
            break;
        case 12:
            strcpy(mes, "Dezembro");
            break;
        default:
            break;
    }
    itoa(d, dia, 10);
    itoa(a, ano, 10);
    strcpy(data, "");
    strcat(data, dia);
    strcat(data, " ");
    strcat(data, mes);
    strcat(data, " ");
    strcat(data, ano);
}

int main () {
    char dia[MAX], mes[MAX], ano[MAX], data[60];
    int n, d, m, a;
    do
    {
        scanf("%d %d %d", &d, &m, &a);
        dataSla(d, m, a, dia, mes, ano, data);
        printf("%s", data);
        scanf("%d", &n);
    } while (n != 0);
}