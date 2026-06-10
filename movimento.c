#include "movimento.h"
#include <string.h>

// Estrutura para armazenar as faces adjacentes
typedef struct {
    int norte;
    int sul;
    int leste;
    int oeste;
} FacesAdjacentes;

// Faces lado a lado ou perto
FacesAdjacentes obter_adjacentes(int face) {
    FacesAdjacentes adj = {0};

    static const int adjacencias[6][4] = {
        {VERDE, AZUL, VERMELHO, LARANJA},    // BRANCO
        {AZUL, VERDE, VERMELHO, LARANJA},    // AMARELO
        {BRANCO, AMARELO, VERMELHO, LARANJA}, // VERDE
        {BRANCO, AMARELO, LARANJA, VERMELHO}, // AZUL
        {BRANCO, AMARELO, VERDE, AZUL},      // LARANJA
        {BRANCO, AMARELO, AZUL, VERDE}       // VERMELHO
    };

    adj.norte = adjacencias[face][0];
    adj.sul = adjacencias[face][1];
    adj.leste = adjacencias[face][2];
    adj.oeste = adjacencias[face][3];

    return adj;
}

// gira uma face individualmente
void rotacionar_face(Cubo* cubo, int face, int sentido) {
    char temp[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = cubo->faces[face][i][j];
        }
    }

    if (sentido == HORARIO) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cubo->faces[face][j][2-i] = temp[i][j];
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cubo->faces[face][2-j][i] = temp[i][j];
            }
        }
    }
}

// Mover linhas entre faces
void mover_linhas(Cubo* cubo, const int faces[4], int linha, int sentido) {
    char temp[3];

    int ordem[4];
    if (sentido == HORARIO) {
        ordem[0] = 0; ordem[1] = 1; ordem[2] = 2; ordem[3] = 3;
    } else {
        ordem[0] = 0; ordem[1] = 3; ordem[2] = 2; ordem[3] = 1;
    }

    for (int i = 0; i < 3; i++) {
        temp[i] = cubo->faces[faces[ordem[0]]][linha][i];
    }

    for (int passo = 0; passo < 3; passo++) {
        int de = ordem[passo + 1];
        int para = ordem[passo];
        for (int i = 0; i < 3; i++) {
            cubo->faces[faces[para]][linha][i] = cubo->faces[faces[de]][linha][i];
        }
    }

    for (int i = 0; i < 3; i++) {
        cubo->faces[faces[ordem[3]]][linha][i] = temp[i];
    }
}

// Mover colunas entre faces
void mover_colunas(Cubo* cubo, const int faces[4], int coluna, int sentido) {
    char temp[3];

    int ordem[4];
    if (sentido == HORARIO) {
        ordem[0] = 0; ordem[1] = 1; ordem[2] = 2; ordem[3] = 3;
    } else {
        ordem[0] = 0; ordem[1] = 3; ordem[2] = 2; ordem[3] = 1;
    }

    for (int i = 0; i < 3; i++) {
        temp[i] = cubo->faces[faces[ordem[0]]][i][coluna];
    }

    for (int passo = 0; passo < 3; passo++) {
        int de = ordem[passo + 1];
        int para = ordem[passo];
        for (int i = 0; i < 3; i++) {
            cubo->faces[faces[para]][i][coluna] = cubo->faces[faces[de]][i][coluna];
        }
    }

    for (int i = 0; i < 3; i++) {
        cubo->faces[faces[ordem[3]]][i][coluna] = temp[i];
    }
}

// Função principal de movimento
int movimento_cubo(Cubo* cubo, int face, int rotacao, int sentido) {
    if (cubo == NULL) return -1;
    if (face < 0 || face > 5) return -1;
    if (rotacao < 0 || rotacao > 3) return -1;
    if (sentido < 0 || sentido > 1) return -1;

    FacesAdjacentes adj = obter_adjacentes(face);

    int faces_para_mover[4];
    int linha_ou_coluna;
    int mover_linha = 1;

    switch(rotacao) {
        case NORTE:
            faces_para_mover[0] = adj.norte;
            faces_para_mover[1] = adj.leste;
            faces_para_mover[2] = adj.sul;
            faces_para_mover[3] = adj.oeste;
            linha_ou_coluna = 0;
            mover_linha = 1;
            break;
        case SUL:
            faces_para_mover[0] = adj.sul;
            faces_para_mover[1] = adj.oeste;
            faces_para_mover[2] = adj.norte;
            faces_para_mover[3] = adj.leste;
            linha_ou_coluna = 2;
            mover_linha = 1;
            break;
        case LESTE:
            faces_para_mover[0] = adj.leste;
            faces_para_mover[1] = adj.sul;
            faces_para_mover[2] = adj.oeste;
            faces_para_mover[3] = adj.norte;
            linha_ou_coluna = 2;
            mover_linha = 0;
            break;
        case OESTE:
            faces_para_mover[0] = adj.oeste;
            faces_para_mover[1] = adj.norte;
            faces_para_mover[2] = adj.leste;
            faces_para_mover[3] = adj.sul;
            linha_ou_coluna = 0;
            mover_linha = 0;
            break;
    }

    if (mover_linha) {
        mover_linhas(cubo, faces_para_mover, linha_ou_coluna, sentido);
    } else {
        mover_colunas(cubo, faces_para_mover, linha_ou_coluna, sentido);
    }

    rotacionar_face(cubo, face, sentido);

    return 0;
}

// Movimentos convencionais
int mover_frente(Cubo* cubo, int sentido) {
    return movimento_cubo(cubo, VERDE, NORTE, sentido);
}

int mover_tras(Cubo* cubo, int sentido) {
    return movimento_cubo(cubo, AZUL, NORTE, sentido);
}

int mover_cima(Cubo* cubo, int sentido) {
    return movimento_cubo(cubo, BRANCO, NORTE, sentido);
}

int mover_baixo(Cubo* cubo, int sentido) {
    return movimento_cubo(cubo, AMARELO, NORTE, sentido);
}

int mover_esquerda(Cubo* cubo, int sentido) {
    return movimento_cubo(cubo, LARANJA, NORTE, sentido);
}

int mover_direita(Cubo* cubo, int sentido) {
    return movimento_cubo(cubo, VERMELHO, NORTE, sentido);
}
