/*
    Autores: 
    Alberto Azevedo Martinez
    Raul Alexandre Gonzalez Augusto

    No programa, primeiro pegamos os nomes e seu nivel de habilidade, depois, organizamos por nivel de habilidade, apos eles separados em habilidade
    criamos os times, colocamos em ordem alfabetica e por fim apresentamos.
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct jogador{
    string nome;
    int h, equipe;
} info_jogador[10010];

bool compara(jogador p1, jogador p2) {return p1.h > p2.h;}

bool organiza(jogador v1, jogador v2){
    if(v1.equipe == v2.equipe) return v1.nome < v2.nome;
	return v1.equipe < v2.equipe;
}

int main(){
    int n, t, i, j;

    scanf("%d %d", &n, &t);

    for(i = 0; i < n; i++){
        cin >> info_jogador[i].nome;
		scanf("%d", &info_jogador[i].h);
    }

    sort(info_jogador, info_jogador+n, compara);

    for(i = 0, j = 1; i < n; i++, j++){
        if(j == t+1){
            j = 1;
        }

        info_jogador[i].equipe = j;
    }

    sort(info_jogador, info_jogador+n, organiza);

    j = 1; printf("Time %d\n", j);

    for(i = 0; i < n; i++){
        cout << info_jogador[i].nome << "\n";

        if(info_jogador[i].equipe != info_jogador[i+1].equipe){
            j++; if(j <= t) printf("\nTime %d\n", j);
        }
    }

    printf("\n");

    return 0;
}