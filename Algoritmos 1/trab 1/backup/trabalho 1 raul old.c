#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define pi 3.14159265359

/*
    Autor: Raul Alexandre Gonzalez Augusto
*/

//Mostra mensagem quando digita opção invalida
void op_invalida() {
    system("cls");
    printf("Opcao invalidade!\n");
    system("pause");
    system("cls");
}

// pergunta se deseja continuar ou não o programa
int continuar() {
    int op;
    do
    {
        printf("Deseja continuar?\n[1] - Sim    [0] - Nao\n");
        scanf("%d", &op);
        if (op != 1 && op != 0) op_invalida();
    } while (op != 1 && op != 0);
    
    return op;
}

//Cria o menu principal do programa
int menu() {
    int op;
    printf("CALCULADORA TRIGONOMETRICA\n\n[1] - Seno        [4] - Cossecante    [7] - Arco Seno\n[2] - Cosseno     [5] - Secante       [8] - Arco Cosseno\n[3] - Tangente    [6] - Cotangente    [9] - Arco tangente\n[0] - Sair\n");
    printf("Escolha a operacao.\n");
    scanf("%d", &op);
    return op;
}

//Menu de seleção entre Graus ou Radianos
int grau_or_rad() {
    int op;
    system("cls");
    printf("[1] - Graus\n[2] - Radianos\n[3] - Voltar    [0] - Sair\nInforme o tipo do valor.\n");
    scanf("%d", &op);
    return op;
}

//Transforma valor de graus em radianos
double grau_to_rad(double n) {
    return n * pi / 180;
}

//Pega valor que o usuário digitar
double valor() {
    double n;
    system("cls");
    printf("Informe o valor: ");
    scanf("%lf", &n);
    return n;
}

//Função principal
int main() {
    int op;
    double n;

    //loop para executar programa enquanto op != 0
    do
    {
        op = menu();

        //dependendo da op executa uma das contas 
        if (op == 1)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                }  
                
                system("cls");
                if (n > 3.14 && n < 3.15) printf("Seno de %.2lf = 0\n\n", n);
                printf("Seno de %.2lf = %.2f\n\n", n, sin(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 2)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                if (n > 1.57 && n < 1.58) printf("Cosseno de %.2lf = 0\n\n", n);
                else printf("Cosseno de %.2lf = %.2f\n\n", n, cos(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 3)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                if (n > 1.57 && n < 1.58) printf("Tangente de %.2lf = indeterminado(divisao por 0)\n\n", n);
                else printf("Tangente de %.2lf = %.2f\n\n", n, tan(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 4)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                printf("Cossecante de %.2lf = %.2f\n\n", n, 1/sin(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 5)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                if (n > 1.57 && n < 1.58) printf("Secante de %.2lf = indeterminado(divisao por 0)\n\n", n);
                else printf("Secante de %.2lf = %.2f\n\n", n, 1/cos(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 6)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                }  
                
                system("cls");
                if (n > 1.57 && n < 1.58) printf("Cotangente de %.2lf = 0\n\n", n);
                else printf("Cotangente de %.2lf = %.2f\n\n", n, 1/tan(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 7)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                if (n > 1 || n < -1) printf("Arco seno de %.2lf = nao determinado (arco seno precisa ser no intervalo [-1,1])\n\n", n);
                else printf("Arco Seno de %.2lf = %.2f\n\n", n, asin(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 8)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0) break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                if (n > 1 || n < -1) printf("Arco cosseno de %.2lf = nao determinado (arco cosseno precisa ser no intervalo [-1,1])\n\n", n);
                else printf("Arco cosseno de %.2lf = %.2f\n\n", n, acos(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op == 9)
        {
            do
            {
                op = grau_or_rad();

                if (op == 1)
                {
                    n = valor();
                    n = grau_to_rad(n);
                } else if ( op == 2) n = valor();
                else if (op == 3 || op == 0)break;
                else if (op < 0 || op > 0)
                {
                    op_invalida();
                    continue;
                } 
                
                system("cls");
                printf("Arco tangente de %.2lf = %.2f\n\n", n, atan(n));
                op = continuar();
            } while (op != 1 && op != 0);
        } else if (op < 0 || op > 0) op_invalida();
        
        system("cls");
    } while (op != 0);
    
    return 0;
}
