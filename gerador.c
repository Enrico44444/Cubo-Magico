#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gerador.h>
#include <time.h>
#include <funcoes.h>

void gerar_cubos(char cubo[6][3][3], int quantidade) {
//CONTADORES SUCESSO OU ERRO NA ABERTURA DE ARQUIVO:
int sucesso = 0;
int erro = 0;

srand(time(NULL));
int face;
int sentido;

FILE * arquivo;

//NOME DO ARQUIVO, 100 CARACTERES PARA O COMPILADOR NÃO RECLAMAR:
char nome[100];

char letras_faces[6] = {'U', 'D', 'F', 'B', 'L', 'R'};

char cubo2[6][3][3];

    //FOR PARA GERAR OS CUBOS:
    for (int i = 0; i < quantidade; i++) {
    
     for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                cubo2[i][j][k] = cubo[i][j][k];      
         }
      }
    }
    //FAZ 20 MOVIMENTOS ALEATÓRIOS NO CUBO:
    for (int r = 0; r < 20; r++){
        face = rand() % 6;
        sentido = rand() % 2;
        mover_cubo(cubo2, face, sentido);
    }

        //DEFINE O NOMNE DO ARQUIVO:
        sprintf(nome, "cubos_gerados/cubo%d.txt", i + 1);

        //ABRE O ARQUIVO:
        arquivo = fopen(nome, "w");
        
        //SE OBTIVEMOS SUCESSO AO TENTAR ABRIR O ARQUIVO:
        if (arquivo != NULL) {
            sucesso++;
            /*GRAVA O CUBO NO FORMATO:
            U
            WWW
            WWW
            WWW
            D
            YYY
            YYY
            YYY
            ...
            */

            for (int f = 0; f < 6; f++) {
                fprintf(arquivo, "%c\n", letras_faces[f]);
                for (int l = 0; l < 3; l++) {
                    for (int c = 0; c < 3; c++) {
                        fprintf(arquivo, "%c", cubo2[f][l][c]);
                    }
                    fprintf(arquivo, "\n");
                }
            }
            
            //FECHA O ARQUIVO:
            fclose(arquivo);
        }
        else{
            erro++;
        }

}
printf("\n%d cub%s gerad%s com sucesso.\n", quantidade, (sucesso > 1) ? "os" : "o", (sucesso > 1) ? "os" : "o");
printf("%d arquiv%s não fo%s criad%s.\n", erro, (sucesso > 1) ? "os" : "o",(sucesso > 1) ? "ram" : "i", (sucesso > 1) ? "os" : "o");
}
