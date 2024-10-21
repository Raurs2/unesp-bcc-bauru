/*
* Autor: Raul Alexandre Gonzalez Augusto
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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

void fillMatrix(int a[MAX][MAX], int lin, int col) {
    int i, j;
    printf("Informe a matriz (%d, %d)\n", lin, col);
    for ( i = 0; i < lin; i++)
        for ( j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
}

void printMatrix(int a[MAX][MAX], int lin, int col) {
    int i, j;
    for ( i = 0; i < lin; i++)
    {
        for ( j = 0; j < col; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void MatrixElements(int *lin, int *col) {
    printf("Informe os elementos da matriz (m, n)\n");
    scanf("%d %d", lin, col);
}

int trocaLinha(int a[MAX][MAX], int col) {
    int i, j, x, y, v1[MAX], v2[MAX];
    printf("Trocar linha x por y (inicia no 0)\n");
    scanf("%d %d", &x, &y);
    for ( i = 0; i < col; i++)
    {
        v1[i] = a[x][i];
        v2[i] = a[y][i];
    }
    for ( i = 0; i < col; i++)
    {
        a[x][i] = v2[i];
        a[y][i] = v1[i];
    }
    return 1;
}

int trocaCol(int a[MAX][MAX], int lin) {
    int i, j, x, y, v1[MAX], v2[MAX];
    printf("Trocar coluna x por y (inicia no 0)\n");
    scanf("%d %d", &x, &y);
    for ( i = 0; i < lin; i++)
    {
        v1[i] = a[i][x];
        v2[i] = a[i][y];
    }
    for ( i = 0; i < lin; i++)
    {
        a[i][x] = v2[i];
        a[i][y] = v1[i];
    }
    return 1;
}

int trocaDiag(int a[MAX][MAX], int lin, int col) {
    int i, j, v1[lin], v2[lin], d;
    if (lin == col)
    {
        for ( i = 0, d = lin-1; i < lin; i++, d--)
            for ( j = 0; j < col; j++)
            {
                if (j == i) v1[i] = a[i][j];
                if (j == d) v2[i] = a[i][j];
            }
        for ( i = 0, d = lin-1; i < lin; i++, d--)
            for ( j = 0; j < col; j++)
            {
                if (j == i) a[i][j] = v2[i];
                if (j == d) a[i][j] = v1[i];
            }
        return 1;
    } else
        return 0;
}

int isSimetrica(int a[MAX][MAX], int lin, int col) {
    int i, j, b[lin][col];

    if (lin == col)
    {
        for ( i = 0; i < lin; i++)
            for ( j = 0; j < col; j++)
                b[j][i] = a[i][j];
        for ( i = 0; i < lin; i++)
            for ( j = 0; j < col; j++)
                if (b[i][j] != a[i][j]) return 0;
        return 1; 
    }
    return 0;
}

int isMagicSquare(int a[MAX][MAX], int lin, int col) {
    int i, j, sumLin[lin], sumCol[lin], sumD[lin], d;
    if (lin == col)
    {
        for ( j = 0; j < lin; j++)
        {
            sumLin[j] = 0;
            sumCol[j] = 0;
            sumD[j] = 0;
        }
        for ( i = 0, d = lin-1; i < lin; i++, d--)
            for ( j = 0; j < col; j++)
            {
                sumLin[i] += a[i][j];
                sumCol[i] += a[j][i];
                if (j == i) sumD[0] += a[i][j];
                if (j == d) sumD[1] += a[i][j];
            } 
        for ( i = 0; i < lin; i++)
            if (sumD[0] != sumD[1] || sumLin[i] != sumCol[i]) return 0;
        return 1;
    }
    return 0;
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenaVetor (int tam, int v[]) {
    int i, j;
    for (i = 0; i < tam-1; i++)
        for (j = i+1; j < tam; j++)
            if (v[i] > v[j]) troca(&v[i],&v[j]);
}

int isLatinSquare(int a[MAX][MAX], int lin, int col) {
    int i, j, v[lin], v2[lin], k;
    if (lin == col)
    {
        for ( i = 0; i < lin; i++)
        {
            v[i] = i+1;
            for ( j = 1; j < col; j++)
            {
                if (a[i][0] == a[i][j] || a[0][i] == a[j][i]) return 0;
            }
        }
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                v2[j] = a[i][j];
            }
            ordenaVetor(lin, v2);
            for ( k = 0; k < lin; k++)
            {
                if (v[k] != v2[k]) return 0;
            }
        }
        
        return 1;
    }
    return 0;
}

int isPermutacao(int a[MAX][MAX], int lin, int col) {
    int i, j, ones = 0, zeros = 0, moreOne = 0, k;
    if (lin == col)
    {
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0, zeros = 0, moreOne = 0, ones = 0; j < col; j++)
            {
                if (a[i][j] == 0) zeros++;
                if (a[i][j] == 1) {
                    ones++;
                    for ( k = i+1; k < lin; k++)
                        if (a[k][j] == 1) moreOne = 1;
                }
            }
            if (zeros + ones > lin || moreOne || ones != 1 || zeros != lin-1) return 0;
        }
        return 1; 
    }
    return 0;
}

int menu() {
    int op = 1, y = 2, tecla, isRunning = 1;

    while (isRunning)
    {
        gotoxy(40, 0); printf("Menu              ESC - sair F1 - ajuda");
        gotoxy(35, 2); printf("-> ");
        gotoxy(40, 2); printf("Informar nova matriz\n");
        gotoxy(40, 3); printf("Mostrar matriz\n");
        gotoxy(40, 4); printf("Trocar linha x por linha y\n");
        gotoxy(40, 5); printf("Trocar coluna x por coluna y\n");
        gotoxy(40, 6); printf("Trocar diagonal principal por diagonal secundaria\n");
        gotoxy(40, 7); printf("Verificar simetria\n");
        gotoxy(40, 8); printf("Verificar se e quadrado magico\n");
        gotoxy(40, 9); printf("Verificar se e quadrado latino\n");
        gotoxy(40, 10); printf("Verificar se e permutacao\n");

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

int main() {
    int lin, col, a[MAX][MAX], op, i, j;

    //MatrixElements(&lin, &col);
    //system("cls");
    //fillMatrix(a, lin, col);
    do
    {
        system("cls");
        op = menu();
        system("cls");
        if (op == 1) {
            MatrixElements(&lin, &col);
            system("cls");
            fillMatrix(a, lin, col);
        } else if (op == 2) {
            printMatrix(a, lin, col);
            system("pause");
        } else if (op == 3) {
            if (trocaLinha(a, col)) printf("Sucesso!\n");
            system("pause");
        } else if (op == 4) {
            if (trocaCol(a, lin)) printf("Sucesso!\n");
            system("pause");
        } else if (op == 5) {
            if (trocaDiag(a, lin, col)) printf("Sucesso!\n");
            else printf("Precisa ser matriz quadrada!\n");
            system("pause");
        } else if (op == 6) {
            if (isSimetrica(a, lin, col)) printf("e simetrica!\n");
            else printf("nao e simetrica!\n");
            system("pause");
        } else if (op == 7) {
            if (isMagicSquare(a, lin, col)) printf("e quadrado magico!\n");
            else printf("nao e quadrado magico!\n");
            system("pause");
        } else if (op == 8) {
            if (isLatinSquare(a, lin, col)) printf("e quadrado latino!\n");
            else printf("nao e quadrado latino!\n");
            system("pause");
        } else if (op == 9) {
            if (isPermutacao(a, lin, col)) printf("e permutacao!\n");
            else printf("nao e permutacao!\n");
            system("pause");
        }
    } while (op != -1);
    return 0;
}