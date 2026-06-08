#include <stdio.h>
#include "funcoes.h"

//Face vai de 0 até 5, nesta ordem: Branco, Amarelo, Verde, Azul, Laranja, Vermelho.
//Rotação vai de 0 até 3, nesta ordem: Norte, Sul, Leste e Oeste.
//Sentido é 0 (anti-horário) ou 1 (horário).

char mover_cubo(char cubo[6][3][3], int face, int rotacao, int sentido) {
//LISTAS QUE FUNCIONARÃO COMO UM MAPA, PARA MAPEAR AONDE OS ADESIVOS DEVEM IR:

//LISTA 1: MOVIMENTOS NORTE E SUL DAS FACES VERDE, LARANJA, VERMELHO E AZUL: 
//DA DIREITA PARA A ESQUERDA VERDE, VERMELHO, AZUL LARANJA.
int lista1[6] = {4,2,5,3,4,2};

//REFERÊNCIA DA FACES QUE ESTÃO EM NORTE E A SUL:
//DEPOIS, TRANSFORMAR EM LISTA PARA SIMPLIFICAR
int lista1_NORTE = 0;
int lista1_SUL = 1;


//LISTA 2: MOVIMENTOS LESTE E OESTE DAS FACES VERDE, LARANJA, VERMELHO E AZUL:
//DE BAIXO PARA CIMA: VERDE, BRANCO, AZUL E AMARELO.
int lista2[6] = {1,2,0,3,1,2};

//REFERÊNCIA DA FACES QUE ESTÃO A LESTE E A OESTE:
//DEPOIS, TRANSFORMAR EM LISTA PARA SIMPLIFICAR
int lista2_LESTE = 6;
int lista2_OESTE = 5;

//LISTA 3: MOVIMENTOS NORTE E SUL DAS FACES BRANCO E AMARELO:
//DA DIREITA PARA A ESQUERDA BRANCO, VERMELHO, AMARELO, LARANJA.
int lista3[6] = {5,0,6,1,5,0};

//REFERÊNCIA DA FACES QUE ESTÃO A NORTE E A SUL:
//DEPOIS, TRANSFORMAR EM LISTA PARA SIMPLIFICAR
int lista3_NORTE = 3;
int lista3_SUL = 2;

//LISTA 4: MOVIMENTOS LESTE E OESTE DAS FACES BRANCO E AMARELO:
//DE BAIXO PARA CIMA: BRANCO, AZUL, AMARELO, VERDE.
int lista4[6] = {2,0,3,1,2,0};

//REFERÊNCIA DAS FACES QUE ESTÃO A LESTE E A OESTE:
//DEPOIS, TRANSFORMAR EM LISTA PARA SIMPLIFICAR
int lista4_LESTE = 5;
int lista4_OESTE = 4;


//UM CUBO TEMPORÁRIO PARA FACILITAR:
char cubo2[6][3][3];
    for (int i = 0; i < 6; i++){
    for (int j = 0; j < 3; j++){
    for (int k = 0; k < 3; k++){
        cubo2[i][j][k] = cubo[i][j][k];
    }}}

//IFS PARA UTILIZAR TODAS ESSAS LISTAS:

        //SE A FACE É VERDE, VERMELHO, AZUL OU LARANJA:
        if (face == 2 || face == 5 || face == 3 || face == 4 ){

            //SE A ROTAÇÃO É NORTE OU SUL:
            if (rotacao == 0 || rotacao == 1){
                //DEFININDO ÍNDICE DE LINHA COM BASE NA ROTAÇÃO:
                int l = (rotacao == 0) ? 0 : 2;
    
                //SE É NO SENTIDO HORÁRIO:
                if (sentido == 0){
                    //FORS PARA MOVER OS ADESIVOS
                    for (int i = 0; i < 3; i++){
                        cubo2[lista1[2]][l][i] = cubo[lista1[1]][l][i];
                        cubo2[lista1[3]][l][i] = cubo[lista1[2]][l][i];
                        cubo2[lista1[4]][l][i] = cubo[lista1[3]][l][i];
                        cubo2[lista1[5]][l][i] = cubo[lista1[4]][l][i];
                    }
                    //FORS PARA MOVER AS FACES DO TOPO OU BASE
                    for (int i = 0; i < 3; i++){
                        for (int j = 0; j < 3; j++){
                            //MEXER NO SENTIDO HORÁRIO, MEXERÁ A FACE NORTE NO SENTIDO ANTI-HORÁRIO E A SUL NO SENTIDO HORÁRIO  
                            if (rotacao == 0){
                                cubo2[lista1_NORTE][2-j][i] = cubo[lista1_NORTE][i][j];
                            }
                            else{
                                cubo2[lista1_SUL][j][2-i] = cubo[lista1_SUL][i][j];
                            }
                        }}
                    }

                //SE É NO SENTIDO ANTI-HORÁRIO:
                if (sentido == 1){
                    //FOR PARA MOVER OS ADESIVOS LATERAIS
                     for (int i = 2; i >= 0; i--){
                        cubo2[lista1[0]][l][i] = cubo[lista1[1]][l][i];
                        cubo2[lista1[1]][l][i] = cubo[lista1[2]][l][i];
                        cubo2[lista1[2]][l][i] = cubo[lista1[3]][l][i];
                        cubo2[lista1[3]][l][i] = cubo[lista1[4]][l][i];
                    }
                    //FOR PARA MOVER AS FACES DO TOPO OU BASE
                    for (int i = 0; i < 3; i++){
                        for (int j = 0; j < 3; j++){   
                            //MEXER NO SENTIDO HORÁRIO, MEXERÁ A FACE NORTE NO SENTIDO HORÁRIO E A SUL NO SENTIDO ANTI-HORÁRIO 
                            if (rotacao == 0){
                                cubo2[lista1_NORTE][j][2-i] = cubo[lista1_NORTE][i][j];
                            }
                            else{
                                cubo2[lista1_SUL][2-j][i] = cubo[lista1_SUL][i][j];
                            }
                        }}
                    }
                //RETORNA O CUBO PARA A FUNÇÃO
                for (int i = 0; i < 6; i++){
                for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                cubo[i][j][k] = cubo2[i][j][k];
                }}}
                return cubo[6][3][3];
            }


        }
}

int solved(char cubo[6][3][3]) {
    for (int f = 0; f < 6; f++) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (cubo[f][l][c] != cubo[f][0][0])
                    return 0;
            }
        }
    }

    return 1;
}
