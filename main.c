#include <gerador.h>
#include <funcoes.h>
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

    //INÍCIO DA INTERAÇÃO:

    int escolha;

    printf("O que deseja fazer?\n1 - Gerar Cubos\n2 - Resolver um cubo\n3 - Modo Sandbox (Movimentar o cubo livremente)\n");
    while (scanf("%d", &escolha) != 1 || (escolha != 1 && escolha != 2 && escolha != 3)){
        printf("Escolha entre 1 e 2!\nO que deseja fazer?\n1 - Gerar Cubos\n2 - Resolver um cubo\n");
        int c;
        //LIMPA O BUFFER:
        while ((c = getchar()) != '\n' && c != EOF);
}
    switch (escolha){
        case 1:
        int n;
        printf("Quantos cubos você deseja gerar?");
        while (scanf("%d", &n) != 1 || (n <= 0)){
            printf("Resposta deve ser um número maior que 0!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        gerar_cubos(cubo, n);
        break;
        
        case 2:
            char nome_arquivo[50];
            char caminho_completo[100];
            
            printf("Digite o nome do arquivo que deseja ler (ex: cubo1.txt): ");
            //LÊ O NOME DO ARQUIVO (LIMITE DE 49 CHARS):
            scanf("%49s", nome_arquivo);

            //MONTA O CAMINHO PARA PASSAR NA FUNÇÃO:
            sprintf(caminho_completo, "cubo_selecionado/%s", nome_arquivo);
            
            //CHAMA A FUNÇÃO:
            if (ler_cubo(caminho_completo, cubo)) {
                printf("Cubo carregado com sucesso a partir de '%s'!\n", nome_arquivo);
                resolver_cubo(cubo);
            } else {
                printf("Falha ao carregar o cubo. Verifique se o nome digitado está correto.\n");
            }
            break;
        case 3:
            char nome_arquivo2[50];
            char caminho_completo2[100];
            
            printf("Digite o nome do arquivo que deseja ler (ex: cubo1.txt): ");
            //LÊ O NOME DO ARQUIVO (LIMITE DE 49 CHARS):
            scanf("%49s", nome_arquivo2);

            //MONTA O CAMINHO PARA PASSAR NA FUNÇÃO:
            sprintf(caminho_completo2, "cubo_selecionado/%s", nome_arquivo2);

            if (ler_cubo(caminho_completo2, cubo)) {
                printf("Cubo carregado com sucesso a partir de '%s'!\n", nome_arquivo2);
                imprime_cubo(cubo);
                printf("Escolha qual face quer mover (0 - 5) e em qual sentido (0 ou 1).\nPara sair, escolha um número fora dos intervalos:\n");
                int f;
                int s;

                printf("Digite a face (0 - 5) e o sentido (0 - 1) a serem utilizados no movimento:\n");
                while (scanf("%d%d", &f, &s) != 1 || (f >= 0 && f <= 5 && (f ==  1 || f == 0))){
                    int c;
                    //LIMPA O BUFFER:
                    while ((c = getchar()) != '\n' && c != EOF);
                    if (f < 0 || f > 5 || s < 0 || s > 1)
                    break;
                    mover_cubo(cubo, f, s);
                    imprime_cubo(cubo);
                    printf("Digite a face (0 - 5) e o sentido (0 - 1) a serem utilizados no movimento:\n");
                }
            } else {
                printf("Falha ao carregar o cubo. Verifique se o nome digitado está correto.\n");
            }
        break;
    }

    return 0;

}