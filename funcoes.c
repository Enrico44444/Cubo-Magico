#include <stdio.h>
#include "funcoes.h"


//Face vai de 0 até 5, nesta ordem: Branco, Amarelo, Verde, Azul, Laranja, Vermelho
//Rotação vai de 0 até 3, nesta ordem: Norte, Sul, Leste Oeste
//Sentido é 0 (anti-horário) ou 1 (horário)
//vermelho leste horario


void mover_cubo(char cubo[6][3][3], int face, int rotacao, int sentido) {
    
}

int solved() {
    int cubo[6][3][3], f, l, c;

    for (f = 0; f < 6; f++) {
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                if (cubo[f][l][c] != cubo[f][0][0])
                    return 0;
            }
        }
    }

    return 1;
}
