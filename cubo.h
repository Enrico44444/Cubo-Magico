#ifndef CUBO_H
#define CUBO_H

typedef struct {
    char faces[6][3][3];
} Cubo;

// Funções básicas
Cubo* cubo_criar(void);
void cubo_destruir(Cubo* cubo);
void cubo_copiar(Cubo* destino, const Cubo* origem);
void cubo_inicializar_resolvido(Cubo* cubo);
void cubo_inicializar_embaralhado(Cubo* cubo);
int cubo_esta_resolvido(const Cubo* cubo);
char cubo_get_cor(const Cubo* cubo, int face, int linha, int coluna);
void cubo_set_cor(Cubo* cubo, int face, int linha, int coluna, char cor);
void cubo_imprimir(const Cubo* cubo);

#endif
