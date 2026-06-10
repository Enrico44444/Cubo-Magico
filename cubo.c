#include "cubo.h"
#include "movimento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Cria um novo cubo (aloca memória)
Cubo* cubo_criar(void) {
    Cubo* cubo = (Cubo*)malloc(sizeof(Cubo));
    if (cubo != NULL) {
        memset(cubo->faces, 0, sizeof(cubo->faces));
    }
    return cubo;
}

// Destroi o cubo (libera memória)
void cubo_destruir(Cubo* cubo) {
    if (cubo != NULL) {
        free(cubo);
    }
}

// COPIA o cubo
void cubo_copiar(Cubo* destino, const Cubo* origem) {
    if (destino == NULL || origem == NULL) return;
    memcpy(destino->faces, origem->faces, sizeof(destino->faces));
}

// Inicializa o cubo no estado resolvido
void cubo_inicializar_resolvido(Cubo* cubo) {
    if (cubo == NULL) return;

    for (int face = 0; face < 6; face++) {
        char cor = (char)face;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cubo->faces[face][i][j] = cor;
            }
        }
    }
}

// Inicializa o cubo com configuração específica (embaralhado)
void cubo_inicializar_embaralhado(Cubo* cubo) {
    if (cubo == NULL) return;

    // Primeiro inicializa o cubo resolvido
    cubo_inicializar_resolvido(cubo);

    // Embaralha aplicando movimentos aleatórios
    srand(time(NULL));

    // Aplica 100 fucking movimentos aleatórios
    for (int i = 0; i < 100; i++) {
        int face = rand() % 6;      // 0-5: BRANCO, AMARELO, VERDE, AZUL, LARANJA, VERMELHO
        int rotacao = NORTE;         // Sempre NORTE para moimentos simples
        int sentido = rand() % 2;    // 0 = HORARIO, 1 = ANTIHORARIO

        movimento_cubo(cubo, face, rotacao, sentido);
    }
}

// Verifica se o cubo está resolvido
int cubo_esta_resolvido(const Cubo* cubo) {
    if (cubo == NULL) return 0;

    for (int face = 0; face < 6; face++) {
        char cor_referencia = cubo->faces[face][0][0];
        for (int linha = 0; linha < 3; linha++) {
            for (int coluna = 0; coluna < 3; coluna++) {
                if (cubo->faces[face][linha][coluna] != cor_referencia) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Retorna a cor de uma posição específica
char cubo_get_cor(const Cubo* cubo, int face, int linha, int coluna) {
    if (cubo == NULL) return -1;
    if (face < 0 || face >= 6) return -1;
    if (linha < 0 || linha >= 3) return -1;
    if (coluna < 0 || coluna >= 3) return -1;

    return cubo->faces[face][linha][coluna];
}

// Define a cor de uma posição específica
void cubo_set_cor(Cubo* cubo, int face, int linha, int coluna, char cor) {
    if (cubo == NULL) return;
    if (face < 0 || face >= 6) return;
    if (linha < 0 || linha >= 3) return;
    if (coluna < 0 || coluna >= 3) return;

    cubo->faces[face][linha][coluna] = cor;
}

// Imprime o cubo no console (para debug)
// TODO: Consertar essa buceta que não alinha
void cubo_imprimir(const Cubo* cubo) {
    if (cubo == NULL) return;

    const char* nomes_faces[] = {"BRANCO", "AMARELO", "VERDE", "AZUL", "LARANJA", "VERMELHO"};
    const char* nomes_cores[] = {"⚪", "🟡", "🟢", "🔵", "🟠", "🔴"};

    printf("\n=== ESTADO DO CUBO ===\n");

    // Imprime face superior (BRANCO)
    // printf("%s:\n", nomes_faces[BRANCO]);
    for (int i = 0; i < 3; i++) {
        printf("       ");
        for (int j = 0; j < 3; j++) {
            int cor = (int)cubo->faces[BRANCO][i][j];  // CONVERTE PARA INT
            printf("%s ", nomes_cores[cor]);
        }
        printf("\n");
    }

    // Imprime as faces do meio (ESQUERDA, FRENTE, DIREITA, TRÁS)
    for (int i = 0; i < 3; i++) {
        // Face esquerda (LARANJA)
        for (int j = 0; j < 3; j++) {
            int cor = (int)cubo->faces[LARANJA][i][j];
            printf("%s ", nomes_cores[cor]);
        }
        printf("  ");

        // Face frente (VERDE)
        for (int j = 0; j < 3; j++) {
            int cor = (int)cubo->faces[VERDE][i][j];
            printf("%s ", nomes_cores[cor]);
        }
        printf("  ");

        // Face direita (VERMELHO)
        for (int j = 0; j < 3; j++) {
            int cor = (int)cubo->faces[VERMELHO][i][j];
            printf("%s ", nomes_cores[cor]);
        }
        printf("  ");

        // Face trás (AZUL)
        for (int j = 0; j < 3; j++) {
            int cor = (int)cubo->faces[AZUL][i][j];
            printf("%s ", nomes_cores[cor]);
        }
        // printf("\n");
    }

    // Imprime face inferior (AMARELO)
    // printf("\n     %s:\n", nomes_faces[AMARELO]);
    for (int i = 0; i < 3; i++) {
        printf("       ");
        for (int j = 0; j < 3; j++) {
            int cor = (int)cubo->faces[AMARELO][i][j];
            printf("%s ", nomes_cores[cor]);
        }
        printf("\n");
    }
    printf("\n");
}
