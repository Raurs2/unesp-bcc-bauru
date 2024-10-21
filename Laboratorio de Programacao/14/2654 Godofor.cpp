#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    usei um struct para definir os parametros dos deuses, depois criei uma funcao que compara cada
    parametro dos deuses entao usei o qsort para ordenar os deuses e printei o primeiro na lista
*/

typedef struct
{
    char name[201];
    int atk, kills, deaths;
} Power;

int cmp(const void *p1, const void *p2)
{
  Power *god1 = (Power *)p1;
  Power *god2 = (Power *)p2;

  int nameDif = strcmp(god1->name, god2->name);

  if (god2->atk - god1->atk == 0)
  {
      if(god2->kills - god1->kills == 0)
        {
            if(god2->deaths - god1->deaths == 0) return nameDif;
            else return (god1->deaths - god2->deaths );    
        }
        else return god2->kills - god1->kills;
  } else return god2->atk - god1->atk;
}


int main()
{

    int nGods;
    scanf("%d\n",&nGods);
    
    Power gods[nGods];

    for(int i = 0; i < nGods; i++)
        scanf("%s %d %d %d\n",gods[i].name,&gods[i].atk,&gods[i].kills,&gods[i].deaths);

    int n = sizeof(gods) / sizeof(gods[0]);
    qsort(gods, n, sizeof(gods[0]), cmp);
    
    printf("%s\n",gods[0].name);

    return 0;   
}