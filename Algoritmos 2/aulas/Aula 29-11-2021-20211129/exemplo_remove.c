#include <stdio.h>
#include <stdlib.h>
int main () {
  // nome do arquivo a ser exclu�do
  char arquivo[15]; //char *arquivo = "vetor.dat";  // char arquivo[15] = "matriz.dat";
  printf ("Digite o nome do arquivo: ");
  gets(arquivo);
  // exclus�o do arquivo
  if (remove(arquivo) == 0)
    printf ("Arquivo foi excluido com sucesso.");
  else
    printf ("Nao foi possivel excluir o arquivo.");
  return 0;
}
