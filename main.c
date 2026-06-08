#include "gerador.h"
#include "funcoes.h"
#include <stdio.h>

int main (){

    // Matriz do Cubo: [Face][Linha][Coluna]

    char cubo[6][3][3] = {
        // Face 0: Branca - Topo
        {
            {'W', 'W', 'B'},
            {'W', 'W', 'B'},
            {'W', 'W', 'B'}
        },
        // Face 1: Amarela - Base
        {
            {'Y', 'Y', 'G'},
            {'Y', 'Y', 'G'},
            {'Y', 'Y', 'G'}
        },
        // Face 2: Verde - Frente
        {
            {'G', 'G', 'W'},
            {'G', 'G', 'W'},
            {'G', 'G', 'W'}
        },
        // Face 3: Azul - Trás
        {
            {'Y', 'B', 'B'},
            {'Y', 'B', 'B'},
            {'Y', 'B', 'B'}
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

cubo[6][3][3] = mover_cubo(cubo,2,0,1);

//IMPRIMIR CUBO
for (int i = 0; i < 6; i++){
    for (int j = 0; j < 3; j++){
    for (int k = 0; k < 3; k++){
        printf("%c", cubo[i][j][k]);
}
printf("\n");
}
printf("\n");
}

    return 0;

}