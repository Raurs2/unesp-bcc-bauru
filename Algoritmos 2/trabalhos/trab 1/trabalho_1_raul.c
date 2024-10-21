#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#define MAX 100
#define ESC 27
#define ENTER 13
#define BAIXO 80
#define CIMA 72
#define F1 59

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
        gotoxy(5, 3); printf("Depositar\n");

        while ((tecla = getch()) != ENTER)
        {
            if (tecla == CIMA && y != 2)
            {
                gotoxy(0, y); printf("   ");
                y--;
                gotoxy(0, y); printf("-> ");
                op--;
            } else if (tecla == BAIXO && y != 10)
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
    char vString[20], *token;
    int i = 0;
    scanf("%s", &vString);
    token = strtok(vString, ".");
    while( token != NULL )
    {
        vInt[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }
}

typedef struct 
{
    int n100, n50, n20, n10, n5, n2, m1;
} notas;

void zerar_notas(notas *n)
{
    (*n).n100 = 0;
    (*n).n50 = 0;
    (*n).n20 = 0;
    (*n).n10 = 0;
    (*n).n5 = 0;
    (*n).n2 = 0;
    (*n).m1 = 0;
}

void converte_notas(notas *n, int v)
{
    while (v != 0)
        {
            if (v / 100 != 0)
            {
                (*n).n100++;
                v -= 100;
            }
            else if (v / 50 != 0)
            {
                (*n).n50++;
                v -= 50;
            }
            else if (v / 20 != 0)
            {
                (*n).n20++;
                v -= 20;
            } else if (v / 10 != 0)
            {
                (*n).n10++;
                v -= 10;
            } else if (v / 5 != 0)
            {
                (*n).n5++;
                v -= 5;
            } else if (v / 2 != 0)
            {
                (*n).n2++;
                v -= 2;
            } else if (v / 1 != 0)
            {
                (*n).m1++;
                v -= 1;
            }
        }
}

void mostra_notas(notas n)
{
    printf("NOTAS:\n");
    printf("R$100: %d\n", n.n100);
    printf("R$50: %d\n", n.n50);
    printf("R$20: %d\n", n.n20);
    printf("R$10: %d\n", n.n10);
    printf("R$5: %d\n", n.n5);
    printf("R$2: %d\n", n.n2);
}

typedef struct 
{
    int m05, m025, m01, m005, m001;
} moedas;

int main()
{
    int vInt[2];
    notas n;
    string_to_int(vInt);
    printf("%d %d\n", vInt[0], vInt[1]);
    zerar_notas(&n);
    converte_notas(&n, vInt);
    mostra_notas(n);
    return 0;
}
