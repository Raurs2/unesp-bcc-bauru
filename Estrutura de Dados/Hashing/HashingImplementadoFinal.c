#include <stdio.h>
#include <math.h>

#define max 100

//Raul Alexandre Gonzalez Augusto
//RA 211023698

typedef struct
{
    int data;
    int key;
} hash_table;

//Método da Divisão
int resto(int key_index, int table_len)
{
    return key_index % table_len;
}

int enlacamento_deslocado(int key, int table_digits)
{
    int key_digits = (int)floor(log10(abs(key))) + 1; //expressao para descobrir qtd. de digitos do numero
    
    //adiciona zeros no final preparando para o uso do metodo
    while (key_digits % table_digits != 0)
    {
        key *= 10;
        key_digits++;
    }

    int i;
    int div = 1;
    
    //preparando o valor para dividir a chave, dependendo da qtd. de digitos da tabela
    for ( i = 0; i < table_digits; i++)
    {
        div *= 10;
    }
    
    int key_index = 0;

    //vai dividindo e somando as partes
    for ( i = 0; i < key_digits/table_digits; i++)
    {
        key_index += key % div;
        key /= div; 
    }
    key_index += key % div;

    return key_index;
}

int tentativa_linear(int key_index, hash_table table[], int table_len, int key)
{
    int key_Newindex;
    int k = 1;
    int i = key_index+1;

    while (i++ != key_index) //repete ate voltar no valor inicial
    {
        key_Newindex = (key_index+k++)%table_len; //formula da tentativa linear


        if (table[key_Newindex].data == -1)
        {
            table[key_Newindex].data = key;
            return 1;
        }

        //para resetar i para o inicio da tabela
        if (i == max)
            i = 0;
    }
    
    return 0;
}

int meio_quadrado(int key, int table_digits)
{
    key = key * key;

    int key_digits = (int)floor(log10(abs(key))) + 1;

    //para retornar o valor se ele ter qtd de digitos <= os digitos da tabela
    // ja que pelo metodo iria selecionar todos os digitos ja da chave
    if (key_digits <= table_digits)
    {
        return key;
    }
    
    int key_array[max];
    int i = key_digits-1;
    int key_temp = key;

    //Faz um vetor em cada posicao com um digito da chave
    while (key_temp != 0)
    {
        key_array[i--] = key_temp % 10;
        key_temp /=  10;
    }

    int key_index = 0;
    int j = table_digits-1;
    int n;

    if (key_array[key_digits-1] == 0)
    {
        n = 0;
    } else n = 1;
    
    // um for que pega do meio da chave ate o tamanho necessario para caber na tabela
    for ( i = key_digits/2 -n; i < key_digits/2 + table_digits; i++, j--)
    {
        // expressao para colocar o valor correto dos digitos, ja que salvei apenas as unidades no vetor
        key_index += key_array[i] * (int)(pow(10.0, (double)(j)));
    }
    return key_index;
}

int encadeamento_interior(int key_index, hash_table table[], int key)
{
    int i;
    int key_temp = key_index;
    //percorre toda a tabela
    for ( i = 0; i < max; i++)
    {
        // se achar posicao vazia coloca chave ai
        if (table[i].data == -1)
        {
            table[i].data = key;
            
            //se tiver vazio a key da posicao onde teve colisao ja coloca a posicao
            if (table[key_index].key == -1)
            {
                table[key_index].key = i;
            } else
            {
                //percorre ate achar uma posicao de key livre
                while (table[key_temp].key != -1)
                {
                    key_temp = table[key_temp].key;
                }
                table[key_temp].key = i;
            }
            return 1;
        }
    }
    return 0;
}

//inicializa a tabela
int init_hash_table(hash_table table[])
{
    int i;
    for ( i = 0; i < max; i++)
    {
        table[i].data = -1;
        table[i].key = -1;
    }
    return 1;
}

//imprime a tabela
int print_table(hash_table table[])
{
    int i;
    for ( i = 0; i < max; i++)
    {
        printf("id[%d]: data->%d key->%d\n", i, table[i].data, table[i].key);
    }
    return 1;
}

int main()
{
    int op, key, table_len = max-1, table_digits, func, colisao;
    hash_table table[max];

    init_hash_table(table);

    table_digits = (int)floor(log10(abs(table_len))) + 1;

    int key_index = 0;
    do
    {
        printf("Escolha a Funcao:\n1 - Meio quadrado\n2 - enlacamento descolado\n");
        scanf("%d", &func);
    } while (func < 1 && func > 2);
    
    do
    {
        printf("Escolha o tratamento de colisao:\n1 - encadeamento interior\n2 - tentativa linear\n");
        scanf("%d", &colisao);
    } while (colisao < 1 && colisao > 2);
    
    do
    {
        printf("\nInserir chave: ");
        scanf("%d", &key);

        if (func == 1)
        {
            key_index = meio_quadrado(key, table_digits);
            key_index = resto(key_index, table_len);
        } else if (func == 2)
        {
            key_index = enlacamento_deslocado(key, table_digits);
            key_index = resto(key_index, table_len);
        }

        if (colisao == 1)
        {
            if (table[key_index].data == -1)
            {
                table[key_index].data = key;
            } else 
            {
                if (!encadeamento_interior(key_index, table, key))
                    printf("Tabela cheia\n");
            }
        } else if (colisao == 2)
        {
            if (table[key_index].data == -1)
            {
                table[key_index].data = key;
            } else
            {
                if (!tentativa_linear(key_index, table, table_len, key))
                    printf("Tabela cheia\n");
            }
        }
        
        printf("1 - Inserir outra chave\n2 - ver tabela e inserir chave\n3 - sair\n");
        scanf("%d", &op);

        if (op == 2) print_table(table);
            
    } while (op != 3);
    
    return 0;
}
