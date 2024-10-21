#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#define MAX 300
#define ESC 27
#define ENTER 13
#define BAIXO 80
#define CIMA 72
#define F1 59
#define BI 15

void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int menu() {
    int op = 1, y = 2, tecla, isRunning = 1;

    while (isRunning)
    {
        gotoxy(0, 0); printf("Menu");
        gotoxy(0, 2); printf("-> ");
        gotoxy(5, 2); printf("Sacar\n");
        gotoxy(5, 3); printf("Cheque\n");

        while ((tecla = getch()) != ENTER)
        {
            if (tecla == CIMA && y != 2)
            {
                gotoxy(0, y); printf("   ");
                y--;
                gotoxy(0, y); printf("-> ");
                op--;
            } else if (tecla == BAIXO && y != 3)
            {
                gotoxy(0, y); printf("   ");
                y++;
                gotoxy(0, y); printf("-> ");
                op++;
            }
            if (tecla == ESC)
            {
                op = -1;
                isRunning = 0;
                break;
            }
        }
        if (tecla == ENTER) isRunning = 0;
    }
    return op;
}

void tempo_agora()
{
    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    printf("Data: %s\n", time_str);
}

void data()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("Data: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void string_to_int(int vInt[])
{
    char vString[BI], *token;
    int i = 0;
    printf("Digite o valor: (Max: bilhoes)");
    scanf("%s", &vString);
    token = strtok(vString, ".");
    while( token != NULL )
    {
        vInt[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }
}

int senha()
{
    // batata123
    char str[20];
    printf("Digite a senha:\n");
    scanf("%s", &str);
    if (!strcmp(str, "batata123")) return 1;
    return 0;
}

void separar(char v[], char v_sep[BI])
{
    char *token;
    int i = 0;
    token = strtok(v, ".,");
    while( token != NULL )
    {
        v_sep[i] = token;
        token = strtok(NULL, ".,");
        i++;
    }
}

void centena(char v[BI], char saida[MAX], int i)
{
    if (v[i] != '0')
    {
        if (v[i] == '1') strcat(saida, "cento");
        if (v[i] == '2') strcat(saida, "duzentos");
        if (v[i] == '3') strcat(saida, "trezentos");
        if (v[i] == '4') strcat(saida, "quatrocentos");
        if (v[i] == '5') strcat(saida, "quinhentos");
        if (v[i] == '6') strcat(saida, "seiscentos");
        if (v[i] == '7') strcat(saida, "setecentos");
        if (v[i] == '8') strcat(saida, "oitocentos");
        if (v[i] == '9') strcat(saida, "novecentos");
        strcat(saida, " e ");
    }
}

void dezena(char v[BI], char saida[MAX], int i, int c)
{
    if (v[i] != '0')
    {
        if (v[i] == '1')
        {
            if (v[i] == '0') strcat(saida, "dez");
            if (v[i] == '1') strcat(saida, "onze");
            if (v[i] == '2') strcat(saida, "doze");
            if (v[i] == '3') strcat(saida, "treze");
            if (v[i] == '4') strcat(saida, "quatorze");
            if (v[i] == '5') strcat(saida, "quinze");
            if (v[i] == '6') strcat(saida, "dezesseis");
            if (v[i] == '7') strcat(saida, "dezessete");
            if (v[i] == '8') strcat(saida, "dezoito");
            if (v[i] == '9') strcat(saida, "dezenove");
        } else
        {
            if (v[i] == '2') strcat(saida, "vinte");
            if (v[i] == '3') strcat(saida, "trinta");
            if (v[i] == '4') strcat(saida, "quarenta");
            if (v[i] == '5') strcat(saida, "cinquenta");
            if (v[i] == '6') strcat(saida, "sessenta");
            if (v[i] == '7') strcat(saida, "setenta");
            if (v[i] == '8') strcat(saida, "oitenta");
            if (v[i] == '9') strcat(saida, "noventa");
            strcat(saida, " e ");
        }
    }
}

void unidade(char v[BI], char saida[MAX], int i)
{
    if (v[i] == '0') strcat(saida, "zero");
    if (v[i] == '1') strcat(saida, "um");
    if (v[i] == '2') strcat(saida, "dois");
    if (v[i] == '3') strcat(saida, "tres");
    if (v[i] == '4') strcat(saida, "quatro");
    if (v[i] == '5') strcat(saida, "cinco");
    if (v[i] == '6') strcat(saida, "seis");
    if (v[i] == '7') strcat(saida, "sete");
    if (v[i] == '8') strcat(saida, "oito");
    if (v[i] == '9') strcat(saida, "nove");
}

void add_zeros(char v[BI], int i)
{
    for ( i; i < BI; i++)
    {
        strcat(v, "0");
    }
}

void cheque()
{
    char vString[BI], saida[MAX] = "";
    int len, d, i, c;
    printf("Digite o valor do cheque (DEVE CONTER 0.00 OU 0,00)\n");
    gets(vString);
    len = strlen(vString);
    d = BI - len;
    printf("\nd %d\n", d);
    printf("\nlen %d\n", len);
    add_zeros(strrev(vString), len);
    printf("\nd %d\n", d);
    printf("\nlen %d\n", len);
    strrev(vString);
    printf("\nd %d\n", d);
    printf("\nlen %d\n", len);
    if (len > 12)
    {
        strcat(saida, " bilhao ");
    } else if (len > 9)
    {
        strcat(saida, " milhao ");
    } else if (len > 6)
    {
        strcat(saida, " mil ");
    } else if (len > 3)
    {

    }
    for (i = 0; i < 12; i += 3)
    {
        centena(vString, saida, i);
        dezena(vString, saida, i+1);
        unidade(vString, saida, i+2);
    }
    system("pause");
}

int main()
{
    int vInt[2], tries = 5, r = 1, op;
    int n100, n50, n20, n10, n5, n2;
    int m1, m05, m025, m01, m001;
    ;
    while (tries != 0 && r != 0 && op != -1)
    {
        if (1) //senha()
        {
            system("cls");
            op = menu();
            if (op == 1)
            {
                system("cls");
                string_to_int(vInt);

                n100 = n50 = n10 = n5 = n2 = m1 = n20 = 0;
                while (vInt[0] != 0)
                {
                    if (vInt[0] / 100 != 0)
                    {
                        n100++;
                        vInt[0] -= 100;
                    }
                    else if (vInt[0] / 50 != 0)
                    {
                        n50++;
                        vInt[0] -= 50;
                    }
                    else if (vInt[0] / 20 != 0)
                    {
                        n20++;
                        vInt[0] -= 20;
                    } else if (vInt[0] / 10 != 0)
                    {
                        n10++;
                        vInt[0] -= 10;
                    } else if (vInt[0] / 5 != 0)
                    {
                        n5++;
                        vInt[0] -= 5;
                    } else if (vInt[0] / 2 != 0)
                    {
                        n2++;
                        vInt[0] -= 2;
                    } else if (vInt[0] / 1 != 0)
                    {
                        m1++;
                        vInt[0] -= 1;
                    }
                }

                m05 = m025 = m01 = m001 = 0;
                while (vInt[1] != 0)
                {
                    if (vInt[1] / 50 != 0)
                    {
                        m05++;
                        vInt[1] -= 50;
                    }
                    else if (vInt[1] / 25 != 0)
                    {
                        m025++;
                        vInt[1] -= 25;
                    }
                    else if (vInt[1] / 10 != 0)
                    {
                        m01++;
                        vInt[1] -= 10;
                    } else if (vInt[1] / 1 != 0)
                    {
                        m001++;
                        vInt[1] -= 1;
                    }
                }

                printf("NOTAS:\nR$100 = %d\nR$50 = %d\nR$20 = %d\nR$10 = %d\nR$5 = %d\nR$2 = %d\n\n", n100, n50, n20, n10, n5, n2);
                printf("MOEDAS:\nR$1 = %d\nR$0.50 = %d\nR$0.25 = %d\nR$0.10 = %d\nR$0.01 = %d\n\n", m1, m05, m025, m01, m001);
                printf("SACANDO...\n");
                Sleep(3000);
                printf("SAQUE CONCLUIDO!\nPressione uma tecla para fechar o sistema\n");
                system("pause");
                op = -1;
            } else if (op == 2)
            {
                system("cls");
                cheque();
            }
            
        } else
        {
            system("cls");
            tries--;
            printf("Senha incorreta. (%d) tentativas restantes\n", tries);
            printf("Deseja continuar?\n0 - nao\n1 - sim\n");
            scanf("%d", &r);
        }
        system("cls");
    }
    
    return 0;
}
