#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>

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

int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}

int menu() {
    int op = 1, y = 2, tecla, isRunning = 1;

    while (isRunning)
    {
        gotoxy(0, 0); printf("Menu              ESC - sair F1 - ajuda");
        gotoxy(0, 2); printf("-> ");
        gotoxy(5, 2); printf("Informar nova matriz\n");
        gotoxy(5, 3); printf("Mostrar matriz\n");
        gotoxy(5, 4); printf("Trocar linha x por linha y\n");
        gotoxy(5, 5); printf("Trocar coluna x por coluna y\n");
        gotoxy(5, 6); printf("Trocar diagonal principal por diagonal secundaria\n");
        gotoxy(5, 7); printf("Verificar simetria\n");
        gotoxy(5, 8); printf("Verificar se e quadrado magico\n");
        gotoxy(5, 9); printf("Verificar se e quadrado latino\n");
        gotoxy(5, 10); printf("Verificar se e permutacao\n");

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
            if (tecla == F1)
            {
                system("cls");
                printf("Programa com intuito de realizar calculos com matrizes. Usar setas cima e baixo para escolher opcao\nF1 a ajuda\nEsc sai do programa\nPara ver o resultado das operacoes utilize o mostrar matriz\nLinha e coluno inicia no 0\n");
                system("pause");
                system("cls");
                break;
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

int main () {
    int op;
    do
    {
        op = menu();
    } while (op != 0);
}