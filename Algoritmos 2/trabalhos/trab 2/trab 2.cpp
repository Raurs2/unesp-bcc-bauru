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
#define BI 16

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
        gotoxy(5, 2); printf("cadastrar\n");
        gotoxy(5, 3); printf("alterar\n");
        gotoxy(5, 3); printf("exclusao logica\n");
        gotoxy(5, 3); printf("exclusao fisica\n");
        gotoxy(5, 3); printf("consultar\n");

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

int main()
{
    
    int op = menu();
    return 0;
}
