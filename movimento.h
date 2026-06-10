#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include "cubo.h"

// Cores das faces
#define BRANCO 0
#define AMARELO 1
#define VERDE 2
#define AZUL 3
#define LARANJA 4
#define VERMELHO 5

// Direções de rotação da camada
#define NORTE 0
#define SUL 1
#define LESTE 2
#define OESTE 3

// Sentidos de rotação
#define HORARIO 0
#define ANTIHORARIO 1

// Declarações das funções
int movimento_cubo(Cubo* cubo, int face, int rotacao, int sentido);
int mover_frente(Cubo* cubo, int sentido);
int mover_tras(Cubo* cubo, int sentido);
int mover_cima(Cubo* cubo, int sentido);
int mover_baixo(Cubo* cubo, int sentido);
int mover_esquerda(Cubo* cubo, int sentido);
int mover_direita(Cubo* cubo, int sentido);

#endif
