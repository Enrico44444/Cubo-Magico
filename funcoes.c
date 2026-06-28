#include <stdio.h>
#include <stdlib.h>
#include <funcoes.h>
#include <time.h>

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
                    cubo2[l2[3]][l][i] = cubo[l2[4]][2-i][ll];
                    cubo2[l2[4]][i][ll] = cubo[l2[5]][l][i];

                    break;
                
                //SENTIDO ANTI-HORÁRIO: 
                case 1:
                    cubo2[l2[1]][l][i] = cubo[l2[0]][i][ll];
                    cubo2[l2[2]][i][ll] = cubo[l2[1]][l][2-i];
                    cubo2[l2[3]][l][i] = cubo[l2[2]][i][ll];
                    cubo2[l2[4]][i][ll] = cubo[l2[3]][l][2-i];
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

void imprime_cubo(char cubo[6][3][3]){
    //IMPRIME A FACE BRANCA NO TOPO:
    for (int i = 0; i < 3; i++){
        printf("         ");
    for (int j = 0; j < 3; j++){
        printf("%c ", cubo[0][i][j]);
    }
    printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 3; i++){
        //IMPRIME A FACE LARANJA COM AS COLUNAS INVERTIDAS, PARA FAZER SENTIDO AO COMPARAR COM UM CUBO REAL:
        for (int j = 0; j < 3; j++){
            printf("%c ", cubo[4][i][2-j]);
        }
        printf("   ");
        //IMPRIME A FACE VERDE:
        for (int j = 0; j < 3; j++){
            printf("%c ", cubo[2][i][j]);
        }
        printf("   ");
        //IMPRIME A FACE VERMELHA:
        for (int j = 0; j < 3; j++){
            printf("%c ", cubo[5][i][j]);
        }
        printf("   ");
        //IMPRIME A FACE AZUL COM AS COLUNAS INVERTIDAS, PARA FAZER SENTIDO AO COMPARAR COM UM CUBO REAL:
        for (int j = 0; j < 3; j++){
            printf("%c ", cubo[3][i][2-j]);
        }
        printf("\n");
    }
    printf("\n");
    //IMPRIME A FACE AMARELA COM AS LINHAS INVERTIDAS, PARA FAZER SENTIDO AO COMPARAR COM UM CUBO REAL:
    for (int i = 0; i < 3; i++){
        printf("         ");
        for (int j = 0; j < 3; j++){
            printf("%c ", cubo[1][2-i][j]);
        }
        printf("\n");
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

int ler_cubo (char *path, char cubo[6][3][3]){
    FILE *arq = fopen(path, "r");
    
    if (arq == NULL) {
        printf("[ERRO] Nao foi possivel abrir o arquivo: %s\n", path);
        return 0;
    }

    char letra_face;
    int indice_face;

    //FOR PARA LER AS 6 FACES:
    for (int i = 0; i < 6; i++) {
        
        //LÊ A LETRA QUE IDENTIFICA A FACE (U=0, D=1, F=2, B=3, L=4, R=5):
        if (fscanf(arq, " %c", &letra_face) != 1) {
            printf("[ERRO] Falha ao ler o identificador da face %d.\n", i);
            fclose(arq);
            return 0;
        }

        //MAPEIA QUE LETRA É CADA FACE:
        switch (letra_face) {
            case 'U': indice_face = 0; break;
            case 'D': indice_face = 1; break;
            case 'F': indice_face = 2; break;
            case 'B': indice_face = 3; break;
            case 'L': indice_face = 4; break;
            case 'R': indice_face = 5; break;
            default:
                printf("[ERRO] Letra de face invalida encontrada: %c\n", letra_face);
                fclose(arq);
                return 0;
        }

        //LÊ O ESTADO DA FACE:
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                //ESPAÇO ANTES DE %C PARA IGNORAR QUEBRAS DE LINHA:
                fscanf(arq, " %c", &cubo[indice_face][l][c]);
            }
        }
    }

    fclose(arq);
    return 1;
}

void resolver_cubo(char cubo[6][3][3]){
    int iter = 0;
    srand(time(NULL));
    int facer;
    int sentidor;

    while(solved(cubo) != 1){
        facer = rand() % 6;
        sentidor = rand() % 2;
        mover_cubo(cubo, facer, sentidor);
        imprime_cubo(cubo);
        iter++;
    }
    printf("Cubo resolvido depois de %d iterações!", iter);
}