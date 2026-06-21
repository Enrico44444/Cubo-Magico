#include "gerador.h"
#include "funcoes.h"
#include <stdio.h>

int main (){

    // Matriz do Cubo: [Face][Linha][Coluna]

    char cubo[6][3][3] = {
        // Face 0: Branca - Topo
        {
            {'W', 'W', 'W'},
            {'W', 'W', 'W'},
            {'W', 'W', 'W'}
        },
        // Face 1: Amarela - Base
        {
            {'Y', 'Y', 'Y'},
            {'Y', 'Y', 'Y'},
            {'Y', 'Y', 'Y'}
        },
        // Face 2: Verde - Frente
        {
            {'G', 'G', 'G'},
            {'G', 'G', 'G'},
            {'G', 'G', 'G'}
        },
        // Face 3: Azul - Trás
        {
            {'B', 'B', 'B'},
            {'B', 'B', 'B'},
            {'B', 'B', 'B'}
        },
        // Face 4: Laranja - Esquerda
        {
            {'O', 'O', 'O'},
            {'O', 'O', 'O'},
            {'O', 'O', 'O'}
        },
        // Face 5: Vermelho - Direita
        {
            {'R', 'R', 'R'},
            {'R', 'R', 'R'},
            {'R', 'R', 'R'}
        }
    };

    //Início da interação:

    int escolha;

    printf("O que deseja fazer?\n1 - Gerar Cubos\n2 - Resolver um cubo\n");
    while (scanf("%d", &escolha) != 1 || (escolha != 1 && escolha != 2)){
        printf("Escolha entre 1 e 2!\nO que deseja fazer?\n1 - Gerar Cubos\n2 - Resolver um cubo\n");
        int c;
        //Limpa o buffer:
        while ((c = getchar()) != '\n' && c != EOF);
}
    switch (escolha){
        case 1:
        int n;
        printf("Quantos cubos você deseja gerar?");
        while (scanf("%d", &n) != 1){
            printf("Digite um número!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        gerar_cubos(n);
        break;
        
        case 2:
        break;
    }

mover_cubo(cubo, 0, 0);
imprime_cubo(cubo);


    return 0;

}