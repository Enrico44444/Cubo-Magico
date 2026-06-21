#ifndef FUNCOES_h
#define FUNCOES_h

void imprime_cubo(char cubo[6][3][3]);
void mover_cubo (char cubo[6][3][3], int face, int sentido);
void rotaciona_face(char cubo[6][3][3], int face, int sentido);
void move_perpendiculares(char cubo[6][3][3], int face, int sentido);
int solved (char cubo[6][3][3]);

#endif