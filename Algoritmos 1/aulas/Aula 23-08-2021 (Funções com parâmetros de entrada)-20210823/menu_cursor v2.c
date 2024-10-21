     
/*
Função: Menu controlado pelas setas direcionais do teclado
Autor: Guilherme Bezerra Fernandes
Data: 17/10/2018
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
 
char a;
short posX = 30, posY = 5;
 
void moveXY(int x, int y, char t[10])
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", t);    
}
 
void menu()
{
    moveXY(32,1, "::: MENU MOVEL :::"); 
    moveXY(33,5,"1- Cadastro");
    moveXY(33,10,"2- Relatorio");
    moveXY(33,15,"1- Sair");
}
 
int main() 
{
    system("color 4F"); 
    moveXY(30,5, "->");
    do
    {       
        menu();
        moveXY(posX, posY, "->");
        a = toupper(getch());
            
        switch(a)
        {
            case 'H':
                if (posY > 5)
                {
                    moveXY(30,posY, "  ");
                    posY-=5;
                    moveXY(30,posY, "->");              
    
                }
            break;
            
            case 'P':
                if (posY < 15)
                {
                    moveXY(30,posY, "  ");
                    posY+=5;
                    moveXY(30,posY, "->");              
                    
                }
            break;
            
            case 13:  //pressionou enter
                if (posY == 5)    //cadastrando...
                {
                    system("cls");
                    moveXY(30,1, ":::::::::CADASTRO:::::::::: ");
                    system("color 2F");
                    
                    system("cls");
                }
                
                if (posY == 10)    //relatorio
                {
                    system("cls");
                    moveXY(30,1, ":::::::::RELATORIO:::::::::: ");
                    system("color 3F");
                    
                    system("cls");
                }
                
                if (posY == 15)
                {
                    system("cls");
                    exit(0);
                 }
            break;
        }
    
    }while(1);
    
    system("pause");
    return 0;
}