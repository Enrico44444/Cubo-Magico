#include <stdio.h>
#include "funcoes.h"

//Face vai de 0 até 5, nesta ordem: Branco, Amarelo, Verde, Azul, Laranja, Vermelho.
//Rotação vai de 0 até 3, nesta ordem: Norte, Sul, Leste e Oeste.
//Sentido é 0 (horário) ou 1 (anti-horário).

void mover_cubo(char cubo[6][3][3], int face, int sentido) {
    rotaciona_face(cubo, face, sentido);
    move_perpendiculares(cubo, face, sentido);
}

void rotaciona_face(char cubo[6][3][3], int face, int sentido){

    //CUBO TEMPORÁRIO
    char cubo2[6][3][3];
    //TROCA LINHAS E COLUNAS DA FACE SELECIONADA USANDO UM CUBO TEMPORÁRIO
    for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        switch (sentido){
        case 0: cubo2[face][j][2-i] = cubo[face][i][j];
        break;
        case 1: cubo2[face][2-j][i] = cubo[face][i][j];
        break;
        }
            }
        }
    //RETORNA O CUBO
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cubo[face][i][j] = cubo2[face][i][j];      
         }
    }
}

void move_perpendiculares(char cubo[6][3][3], int face, int sentido){
    
    //LISTAS:

    //LISTA FACES BRANCO E AMARELO:
    int l1[6] = {4,2,5,3,4,2};

    //LISTA FACES VERDE E AZUl:
    int l2[6] = {5,0,4,1,5,0};

    //LISTA FACES LARANJA E VERMELHO:
    int l3[6] = {3,0,2,1,3,0};

    //CUBO TEMPORÁRIO
    char cubo2[6][3][3];
     for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                cubo2[i][j][k] = cubo[i][j][k];      
         }
    }
    }

    //ROTAÇÃO PARA AS FACES PERPENDICULARES A BRANCA E AMARELA
    if (face == 0 || face == 1){

        //VARIÁVEL PARA A LINHA
        int l = (face == 0) ? 0 : 2;

        for (int i = 0; i < 3; i++){
            switch (sentido){
                
                //SENTIDO HORÁRIO:
                case 0:
                    cubo2[l1[1]][l][i] = cubo[l1[2]][l][i];
                    cubo2[l1[2]][l][i] = cubo[l1[3]][l][2-i];
                    cubo2[l1[3]][l][i] = cubo[l1[4]][l][i];
                    cubo2[l1[4]][l][i] = cubo[l1[5]][l][2-i];
                    break;
                
                //SENTIDO ANTI-HORÁRIO: 
                case 1:
                    cubo2[l1[1]][l][i] = cubo[l1[0]][l][2-i];
                    cubo2[l1[2]][l][i] = cubo[l1[1]][l][i];
                    cubo2[l1[3]][l][i] = cubo[l1[2]][l][2-i];
                    cubo2[l1[4]][l][i] = cubo[l1[3]][l][i];
                    break;
                }
        }
    }
   //ROTAÇÃO PARA AS FACES PERPENDICULARES A VERDE E AZUL
    else if (face == 2 || face == 3){
        
        //VARIÁVEIS PARA OS ÍNDICES:
        int l = (face == 2) ? 2 : 0;
        int ll = (face == 2) ? 0 : 2;
        for (int i = 0; i < 3; i++){
            switch (sentido){
                
                //SENTIDO HORÁRIO:
                case 0:
                    cubo2[l2[1]][l][i] = cubo[l2[2]][2-i][ll];
                    cubo2[l2[2]][i][ll] = cubo[l2[3]][l][i];
                    cubo2[l2[3]][l][i] = cubo[l2[4]][i][ll];
                    cubo2[l2[4]][i][ll] = cubo[l2[5]][l][i];

                    break;
                
                //SENTIDO ANTI-HORÁRIO: 
                case 1:
                    cubo2[l2[1]][l][i] = cubo[l2[0]][i][ll];
                    cubo2[l2[2]][i][ll] = cubo[l2[1]][l][2-i];
                    cubo2[l2[3]][l][i] = cubo[l2[2]][i][ll];
                    cubo2[l2[4]][i][ll] = cubo[l2[3]][l][i];
                    break;
                }
        }
    }
    //ROTAÇÃO PARA AS FACES PERPENDICULARES A LARANJA E VERMELHA
     else {
        int l = (face == 4) ? 0 : 2 ;
        for (int i = 0; i < 3; i++){
            switch (sentido){
                //SENTIDO HORÁRIO:
                case 0:
                    cubo2[l3[1]][i][l] = cubo[l3[2]][i][l];
                    cubo2[l3[2]][i][l] = cubo[l3[3]][2-i][l];
                    cubo2[l3[3]][i][l] = cubo[l3[4]][i][l];
                    cubo2[l3[4]][i][l] = cubo[l3[5]][2-i][l];
                    break;
                
                //SENTIDO ANTI-HORÁRIO: 
                case 1:
                    cubo2[l3[1]][i][l] = cubo[l3[0]][2-i][l];
                    cubo2[l3[2]][i][l] = cubo[l3[1]][i][l];
                    cubo2[l3[3]][i][l] = cubo[l3[2]][2-i][l];
                    cubo2[l3[4]][i][l] = cubo[l3[3]][i][l];
                    break;
                }
        }
    }
    //RETORNA O CUBO
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                cubo[i][j][k] = cubo2[i][j][k];      
         }
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