#include <stdio.h>
#include <time.h>

int main()
{
    int m;
    char mes[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    m = tm.tm_mon + 1;
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
    printf("data agora: %d-%s-%02d %02d:%02d:%02d\n", tm.tm_mday, mes, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}