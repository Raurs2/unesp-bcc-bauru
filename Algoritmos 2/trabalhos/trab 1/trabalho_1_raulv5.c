#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// AUTOR: Raul Alexandre Gonzalez Augusto

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

//cria o menu
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

//pega a data local e imprime
void data()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("Emitido em: %d-%02d-%02d\n\n\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

//pega e separa um numero com virgula
void string_to_int(int vInt[])
{
    char vString[BI], *token;
    int i = 0;
    do
    {
        printf("Digite o valor: (Max: bilhoes DEVE CONTER 0.00 OU 0,00)\n");
        scanf("%s", &vString);
        system("cls");
    } while (!validar(vString));
    token = strtok(vString, ".");
    while( token != NULL )
    {
        vInt[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }
}

//senha de entrada
int senha()
{
    // batata123
    char str[20];
    printf("Digite a senha:\n");
    scanf("%s", &str);
    if (!strcmp(str, "batata123")) return 1;
    return 0;
}

//para separar a string
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

//o que imprimir nas centenas
int centena(char v[BI], char saida[MAX], int i)
{
    if (v[i] != '0')
    {
        if (v[i] == '1' && (v[i+1] != '0' || v[i+2] != '0')) strcat(saida, "cento");
        else if (v[i] == '1') strcat(saida, "cem");
        if (v[i] == '2') strcat(saida, "duzentos");
        if (v[i] == '3') strcat(saida, "trezentos");
        if (v[i] == '4') strcat(saida, "quatrocentos");
        if (v[i] == '5') strcat(saida, "quinhentos");
        if (v[i] == '6') strcat(saida, "seiscentos");
        if (v[i] == '7') strcat(saida, "setecentos");
        if (v[i] == '8') strcat(saida, "oitocentos");
        if (v[i] == '9') strcat(saida, "novecentos");
        strcat(saida, " ");
        if (v[i+1] != '0' || v[i+2] != '0') strcat(saida, "e ");
        return 1;
    }
    return 0;
}

//o que imprimir nas dezenas
int dezena(char v[BI], char saida[MAX], int i)
{
    if (v[i] != '0')
    {
        if (v[i] == '1')
        {
            if (v[i] == '1' && v[i+1] == '0') strcat(saida, "dez");
            if (v[i] == '1' && v[i+1] == '1') strcat(saida, "onze");
            if (v[i] == '1' && v[i+1] == '2') strcat(saida, "doze");
            if (v[i] == '1' && v[i+1] == '3') strcat(saida, "treze");
            if (v[i] == '1' && v[i+1] == '4') strcat(saida, "quatorze");
            if (v[i] == '1' && v[i+1] == '5') strcat(saida, "quinze");
            if (v[i] == '1' && v[i+1] == '6') strcat(saida, "dezesseis");
            if (v[i] == '1' && v[i+1] == '7') strcat(saida, "dezessete");
            if (v[i] == '1' && v[i+1] == '8') strcat(saida, "dezoito");
            if (v[i] == '1' && v[i+1] == '9') strcat(saida, "dezenove");
            strcat(saida, " ");
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
            strcat(saida, " ");
            if (v[i+1] != '0') strcat(saida, "e ");
        }
        return 1;
    }
    return 0;
}

//o que imprimir nas unidades
int unidade(char v[BI], char saida[MAX], int i)
{
    if (v[i-1] != '1' && v[i] != '0')
    {
        if (v[i] == '1' && i == 8) strcat(saida, "mil");
        else if (v[i] == '1') strcat(saida, "um");
        if (v[i] == '2') strcat(saida, "dois");
        if (v[i] == '3') strcat(saida, "tres");
        if (v[i] == '4') strcat(saida, "quatro");
        if (v[i] == '5') strcat(saida, "cinco");
        if (v[i] == '6') strcat(saida, "seis");
        if (v[i] == '7') strcat(saida, "sete");
        if (v[i] == '8') strcat(saida, "oito");
        if (v[i] == '9') strcat(saida, "nove");
        strcat(saida, " ");
        return 1;
    }
    if (v[14] == '0' && i == 14 && v[13] == '0') strcat(saida, "zero");
    return 0;
}

// para adicionar zeros nos espacos em brancos da string
void add_zeros(char v[BI], int i)
{
    for ( i; i < BI; i++)
        strcat(v, "0");
}

// a funcao para imprimir o cheque
void cheque()
{
    char vString[BI], saida[MAX] = "", original[BI];
    int i, len_minus, r1 = 0, r2 = 0, r3 = 0, sum = 0;
    do
    {
        fflush(stdin);
        printf("Digite o valor do cheque (MAX BILHOES, DEVE CONTER 0.00 OU 0,00)\n");
        gets(vString);
        system("cls");
    } while (!validar(vString));
    

    strcpy(original, vString);
    add_zeros(strrev(vString), strlen(original));
    strrev(vString);
    len_minus = strlen(original) - 3;

    for (i = 0; i < 12; i += 3)
    {
        r1 = centena(vString, saida, i);
        r2 = dezena(vString, saida, i+1);
        r3 = unidade(vString, saida, i+2);

        sum += r1 + r2 + r3;
        if (len_minus > 9)
        {
            if (vString[i] == '0' && vString[i+1] == '0' && vString[i+2] == '1')
                strcat(saida, " bilhao ");
            else
                strcat(saida, " bilhoes ");
            len_minus = 7;
        } else if (len_minus > 6 && (r1 || r2 || r3))
        {
            if (vString[i] == '0' && vString[i+1] == '0' && vString[i+2] == '1')
                strcat(saida, " milhao ");
            else
                strcat(saida, " milhoes ");
            len_minus = 4;
        } else if (len_minus > 3 && (r1 || r2 || r3))
        {
            if (vString[i] == '0' && vString[i+1] == '0' && vString[i+2] == '1')
            {
                
            } else
                strcat(saida, " mil ");
            len_minus = 2;
        }
        r1 = r2 = r3 = 0;
        if (sum == 0 && i == 11) strcat(saida, " zero ");
    }

    if (sum == 1 && vString[11] == '1')
        strcat(saida, " real ");
    else
        strcat(saida, " reais ");

    strcat(saida, " e ");
    dezena(vString, saida, 13);
    unidade(vString, saida, 14);
    
    if (vString[13] == '0' && vString[14] == '1')
        strcat(saida, " centavo ");
    else
        strcat(saida, " centavos ");

    printf("\n%s\n", saida);
    data();
}

// valida se a string é no max 999 bilhoes e tem .00 ou ,00
int validar(char v[BI])
{
    int i, tem = 0, tam = 1;
    for ( i = 0; i < BI; i++)
    {
        if (v[i] == '.' || v[i] == ',') tem = 1;
    }
    if (strlen(v) > 15) tam = 0;
    return tem && tam;
}

int main()
{
    int vInt[2], tries = 5, r = 1, op;
    int n100, n50, n20, n10, n5, n2;
    int m1, m05, m025, m01, m001;

    while (tries != 0 && r != 0 && op != -1)
    {
        if (senha()) //batata123
        {
            system("cls");
            fflush(stdin);
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
                printf("SAINDO...\n");
                Sleep(3000);
                op = -1;
            } else if (op == 2)
            {
                system("cls");
                cheque();
                printf("IMPRIMINDO CHEQUE...\n");
                Sleep(3000);
                printf("CHEQUE IMPRIMIDO COM SUCESSO!\nPressione uma tecla para fechar o sistema\n");
                system("pause");
                printf("SAINDO...\n");
                Sleep(3000);
                op = -1;
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