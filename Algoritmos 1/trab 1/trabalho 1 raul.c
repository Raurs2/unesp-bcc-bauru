#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
//Pega valor que o usuário digitar
double valor() {
    double n;
    system("cls");
    printf("Informe o valor: ");
    scanf("%lf", &n);
    return n;
}
//Verifica se existe valor na função trigonométrica
int indeterminado(double n, int op, int op2) {
    if (op2 == 2 && op < 7) n = (int)(n*180/M_PI);
    if ((op == 6 || op == 4) && ((int)(n)%180 == 0 || (int)(n) == 0)) return 1;
    if ((op == 3 || op == 5) && ((int)(n)%90 == 0 && (int)(n)%180 != 0)) return 1;
    if ((op == 7 || op == 8) && (n > 1 || n < -1)) return 1;
    return 0;
}
//Função principal
int main() {
    int op, op2, op3;
    double n;
    //loop para executar programa enquanto op != 0
    do
    {
        op = menu();
        //loop para pegar o valor
        if (op >= 1 && op <= 9) {
            do
            {
                op2 = grau_or_rad();
                op3 = 1;
                if (op2 < 3 && op2 > 0) {
                    n = valor();
                    if (indeterminado(n, op, op2)) {
                        printf("Valor indeterminado!\n");
                        system("pause");
                        op2 = -1;
                        continue;
                    }
                }
                if (op2 == 1 && op < 7) n = n * M_PI / 180;
                else if (op2 == 3) op3 = 0;
                else if (op2 == 0) op = 0;
                else if (op2 < 0 || op2 > 3) op_invalida();
            } while (op2 < 0 || op2 > 3);
        }
        system("cls");
        //dependendo da op e se pegou valor executa uma das contas
        if (op3) { 
            if (op == 1)
            {
                    printf("Seno de %.2lf rad = %.2f\n\n", n, sin(n));
                    op = continuar();
            } else if (op == 2)
            {
                    printf("Cosseno de %.2lf = %.2f\n\n", n, cos(n));
                    op = continuar();
            } else if (op == 3)
            {
                    printf("Tangente de %.2lf = %.2f\n\n", n, tan(n));
                    op = continuar();
            } else if (op == 4)
            {
                    printf("Cossecante de %.2lf = %.2f\n\n", n, 1/sin(n));
                    op = continuar();
            } else if (op == 5)
            {
                    printf("Secante de %.2lf = %.2f\n\n", n, 1/cos(n));
                    op = continuar();
            } else if (op == 6)
            {
                    printf("Cotangente de %.2lf = %.2f\n\n", n, 1/tan(n));
                    op = continuar();
            } else if (op == 7)
            {
                    if (op2 == 1) printf("Arco Seno de %.2lf = %d\n\n", n, (int)(asin(n)*180/M_PI));
                    else if (op2 == 2) printf("Arco Seno de %.2lf = %.2lf\n\n", n, asin(n));
                    op = continuar();
            } else if (op == 8)
            {
                    if (op2 == 1) printf("Arco cosseno de %.2lf = %d\n\n", n, (int)(acos(n)*180/M_PI));
                    else if (op2 == 2) printf("Arco cosseno de %.2lf = %.2f\n\n", n, acos(n));
                    op = continuar();
            } else if (op == 9)
            {
                    if (op2 == 2) printf("Arco tangente de %.2lf = %.2f\n\n", n, atan(n));
                    else if (op2 == 1) printf("Arco tangente de %.2lf = %d\n\n", n, (int)(atan(n)*180/M_PI));
                    op = continuar();
            } else if (op < 0 || op > 9) op_invalida();
        }
        system("cls");
    } while (op != 0);    
    return 0;
}