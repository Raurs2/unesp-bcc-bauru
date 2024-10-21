/*
    Autores: 
    Alberto Azevedo Martinez
    Raul Alexandre Gonzalez Augusto
*/

#include<stdio.h>
#include<stdio.h>
#include<math.h>

/*
    pegamos os vertices depois pesquisamos uma formula de calcular um quadrilatero pelos vertices e encontramos nesse site: https://www.onlinemath4all.com/area-of-quadrilateral-when-four-vertices-are-given.html
    depois de calcular a area dos dois terrenos comparamos para saber qual tem a maior area
*/

int main()
{
    int xA[5], yA[5], xB[5], yB[5];

    for (int i = 0; i < 4; i++)
        scanf("%d %d", &xA[i], &yA[i]);

    for (int i = 0; i < 4; i++)
        scanf("%d %d", &xB[i], &yB[i]);
    
    double areaA, areaB;
    areaA = fabs(0.5 * ((xA[0]*yA[1] + xA[1]*yA[2] + xA[2]*yA[3] + xA[3]*yA[0]) - (xA[1]*yA[0] + xA[2]*yA[1] + xA[3]*yA[2] + xA[0]*yA[3])));
    areaB = fabs(0.5 * ((xB[0]*yB[1] + xB[1]*yB[2] + xB[2]*yB[3] + xB[3]*yB[0]) - (xB[1]*yB[0] + xB[2]*yB[1] + xB[3]*yB[2] + xB[0]*yB[3])));
    
    if (areaA > areaB) printf("terreno A\n");
    else printf("terreno B\n");
    
    return 0;
}
