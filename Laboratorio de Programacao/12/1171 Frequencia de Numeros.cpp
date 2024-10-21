#include<stdio.h>

/*

*/

void selectSort_v2(int n, int v[]){
  int aux, i, j, pos_menor;
  for (i = 0; i < n-1; i++) {
    pos_menor = i;  
    for(j = i+1; j < n; j++)
      if (v[j] < v[pos_menor])
        pos_menor = j;
    if (pos_menor != i){
      aux = v[i];
      v[i] = v[pos_menor];
      v[pos_menor] = aux;
    }
  }
}

int main()
{
    int n, x[2001], d;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    
    selectSort_v2(n, x);

    d = 1;
    for (int i = 0; i < n; i++)
    {
        if (x[i] != x[i+1])
        {
            printf("%d aparece %d vez(es)\n", x[i], d);
            d = 1;
        } else d++;
    }

    return 0;
}
