#include <cstdio>
#include <cstdlib>

using namespace std;

// Função usada pela função qsort para comparar dois elementos
int funcComparacao(const void *pv1, const void *pv2) {
  int v1 = *(int *)pv1;
  int v2 = *(int *)pv2;
  return v1 - v2;
}

// Função usada pela função qsort para comparar dois elementos em ordem
// invertida
int funcComparacaoInvertida(const void *pv1, const void *pv2) {
  int v1 = *(int *)pv1;
  int v2 = *(int *)pv2;
  return v2 - v1;
}

int main() {
  int n;
  scanf("%d", &n);
  int vet[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  /*
    A função qsort() é generica, ela pode ordenar qualquer tipo de dados
    incluindo vetores de estruturas.

    O tamanho de cada elemento do vetor deve ser passado no 3º parâmetro da
    chamada de qsort e a função que compara os elementos do vetor no último
    parâmetro de qsort.
    */
  qsort(vet, n, sizeof(vet[0]), funcComparacao);
  printf("Imprime ordenado\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");

  // Note que apenas a função de comparação fou alterada.
  qsort(vet, n, sizeof(vet[0]), funcComparacaoInvertida);
  printf("Imprime ordenado decrescente\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
  return 0;
}