#include <stdio.h>
#include <stdlib.h>
int main () {
  // nome dos arquivos a ser manipulados
  char nome1[15], nome2[15]; 
  printf ("Digite o nome atual do arquivo: ");
  gets(nome1);
  printf ("Digite o nome novo do arquivo: ");
  gets(nome2);
  // troca de nome do arquivo
  if (rename(nome1,nome2) == 0)
    printf ("Arquivo %s teve o nome trocado com sucesso.",nome1);
  else
    printf ("Nao foi possivel trocar o nome do arquivo %s.",nome1);
  return 0;
}
