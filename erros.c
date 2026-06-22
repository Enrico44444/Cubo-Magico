
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* cubo resolvido: U=W, D=Y, F=G, B=B, L=O, R=R */
char cubo[6][3][3];
char cores[] = {'W', 'Y', 'G', 'B', 'O', 'R'};

void resetCubo() {
   int f, i, j;
   for (f = 0; f < 6; f++)
       for (i = 0; i < 3; i++)
           for (j = 0; j < 3; j++)
               cubo[f][i][j] = cores[f];
}

/* rotaciona matriz 3x3 no sentido horario */
void rotacionarFace(int f) {
   char tmp[3][3];
   int i, j;
   for (i = 0; i < 3; i++)
       for (j = 0; j < 3; j++)
           tmp[j][2 - i] = cubo[f][i][j];
   for (i = 0; i < 3; i++)
       for (j = 0; j < 3; j++)
           cubo[f][i][j] = tmp[i][j];
}

/* movimentos: U, D, F, B, L, R (horario) */
void moverU() {
   char tmp[3];
   int j;
   rotacionarFace(0);
   for (j = 0; j < 3; j++) tmp[j] = cubo[2][0][j];
   for (j = 0; j < 3; j++) cubo[2][0][j] = cubo[5][0][j];
   for (j = 0; j < 3; j++) cubo[5][0][j] = cubo[3][0][j];
   for (j = 0; j < 3; j++) cubo[3][0][j] = cubo[4][0][j];
   for (j = 0; j < 3; j++) cubo[4][0][j] = tmp[j];
}

void moverD() {
   char tmp[3];
   int j;
   rotacionarFace(1);
   for (j = 0; j < 3; j++) tmp[j] = cubo[2][2][j];
   for (j = 0; j < 3; j++) cubo[2][2][j] = cubo[4][2][j];
   for (j = 0; j < 3; j++) cubo[4][2][j] = cubo[3][2][j];
   for (j = 0; j < 3; j++) cubo[3][2][j] = cubo[5][2][j];
   for (j = 0; j < 3; j++) cubo[5][2][j] = tmp[j];
}

void moverF() {
   char tmp[3];
   int i;
   rotacionarFace(2);
   for (i = 0; i < 3; i++) tmp[i] = cubo[0][2][i];
   for (i = 0; i < 3; i++) cubo[0][2][i] = cubo[4][2 - i][2];
   for (i = 0; i < 3; i++) cubo[4][i][2] = cubo[1][0][i];
   for (i = 0; i < 3; i++) cubo[1][0][i] = cubo[5][i][0];
   for (i = 0; i < 3; i++) cubo[5][2 - i][0] = tmp[i];
}

void moverB() {
   char tmp[3];
   int i;
   rotacionarFace(3);
   for (i = 0; i < 3; i++) tmp[i] = cubo[0][0][i];
   for (i = 0; i < 3; i++) cubo[0][0][i] = cubo[5][i][2];
   for (i = 0; i < 3; i++) cubo[5][2 - i][2] = cubo[1][2][i];
   for (i = 0; i < 3; i++) cubo[1][2][i] = cubo[4][i][0];
   for (i = 0; i < 3; i++) cubo[4][2 - i][0] = tmp[i];
}

void moverL() {
   char tmp[3];
   int i;
   rotacionarFace(4);
   for (i = 0; i < 3; i++) tmp[i] = cubo[0][i][0];
   for (i = 0; i < 3; i++) cubo[0][i][0] = cubo[3][2 - i][2];
   for (i = 0; i < 3; i++) cubo[3][2 - i][2] = cubo[1][i][0];
   for (i = 0; i < 3; i++) cubo[1][i][0] = cubo[2][i][0];
   for (i = 0; i < 3; i++) cubo[2][i][0] = tmp[i];
}

void moverR() {
   char tmp[3];
   int i;
   rotacionarFace(5);
   for (i = 0; i < 3; i++) tmp[i] = cubo[0][i][2];
   for (i = 0; i < 3; i++) cubo[0][i][2] = cubo[2][i][2];
   for (i = 0; i < 3; i++) cubo[2][i][2] = cubo[1][i][2];
   for (i = 0; i < 3; i++) cubo[1][i][2] = cubo[3][2 - i][0];
   for (i = 0; i < 3; i++) cubo[3][2 - i][0] = tmp[i];
}

void embaralhar(int movimentos) {
   char *nomes[] = {"U", "D", "F", "B", "L", "R"};
   int m, mov;
   for (m = 0; m < movimentos; m++) {
       mov = rand() % 6;
       printf("  %s", nomes[mov]);
       if      (mov == 0) moverU();
       else if (mov == 1) moverD();
       else if (mov == 2) moverF();
       else if (mov == 3) moverB();
       else if (mov == 4) moverL();
       else               moverR();
   }
   printf("\n");
}

void salvarCubo(char *nomeArquivo) {
   FILE *arq;
   char *faces[] = {"U", "D", "F", "B", "L", "R"};
   int f, i, j;

   arq = fopen(nomeArquivo, "w");
   if (arq == NULL) {
       printf("Erro ao criar arquivo '%s'\n", nomeArquivo);
       return;
   }

   for (f = 0; f < 6; f++) {
       fprintf(arq, "%s\n", faces[f]);
       for (i = 0; i < 3; i++) {
           for (j = 0; j < 3; j++)
               fprintf(arq, "%c", cubo[f][i][j]);
           fprintf(arq, "\n");
       }
   }

   fclose(arq);
}

int main(int argc, char *argv[]) {
   int N, i;
   char nomeArquivo[50];

   if (argc != 2) {
       printf("Uso: %s <N>\n", argv[0]);
       return 1;
   }

   N = atoi(argv[1]);
   if (N <= 0) {
       printf("Erro: N deve ser maior que 0\n");
       return 1;
   }

   srand(time(NULL));

   for (i = 0; i < N; i++) {
       resetCubo();
       sprintf(nomeArquivo, "cubo%d.txt", i + 1);
       printf("Gerando %s | movimentos:", nomeArquivo);
       embaralhar(20);
       salvarCubo(nomeArquivo);
       printf("Salvo: %s\n", nomeArquivo);
   }

   return 0;
}
    