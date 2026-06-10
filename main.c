#include <stdio.h>
#include "cubo.h"
#include "movimento.h"

int main() {
    // Criar uma função intuitiva pra resolver na mão ou qualquer coisa do gênero
    printf("=== TESTE DO CUBO MÁGICO ===\n\n");

    // Cria o cubo
    Cubo* meu_cubo = cubo_criar();

    // Teste 1: Cubo resolvido
    printf("1. Inicializando cubo resolvido:\n");
    cubo_inicializar_resolvido(meu_cubo);
    cubo_imprimir(meu_cubo);

    // Teste 2: Aplicar movimentos
    printf("\n2. Aplicando movimentos (Cima Horário, Direita Horário):\n");
    mover_cima(meu_cubo, HORARIO);
    mover_direita(meu_cubo, HORARIO);
    cubo_imprimir(meu_cubo);

    // Teste 3: Verificar se está resolvido
    if (cubo_esta_resolvido(meu_cubo)) {
        printf("Cubo está resolvido!\n");
    } else {
        printf("Cubo NÃO está resolvido (como esperado)\n");
    }

    // Teste 4: Embaralhar
    printf("\n3. Embaralhando o cubo:\n");
    cubo_inicializar_embaralhado(meu_cubo);
    cubo_imprimir(meu_cubo);

    // Libera memória
    cubo_destruir(meu_cubo);

    printf("\n=== FIM DOS TESTES ===\n");
    return 0;
}
