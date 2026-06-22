#include <stdio.h>
#include <string.h>

char cubo[6][3][3];
char *faces[] = {"TOPO", "BASE", "FRENTE", "TRAS", "ESQUERDA", "DIREITA"};

int corValida(char c) {
    return (c == 'W' || c == 'Y' || c == 'G' ||
            c == 'B' || c == 'O' || c == 'R');
}

int lerCubo(char *nomeArquivo) {
    FILE *arq;
    char linha[20];
    char palavra[20];
    int face, i, j;

    arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro: arquivo '%s' nao encontrado\n", nomeArquivo);
        return 0;
    }

    for (face = 0; face < 6; face++) {
        if (fscanf(arq, "%s", palavra) != 1) {
            printf("Erro: arquivo incompleto na face %d\n", face + 1);
            fclose(arq);
            return 0;
        }

        if (strcmp(palavra, faces[face]) != 0) {
            printf("Erro: esperava '%s', encontrou '%s'\n", faces[face], palavra);
            fclose(arq);
            return 0;
        }

        for (i = 0; i < 3; i++) {
            if (fscanf(arq, "%s", linha) != 1) {
                printf("Erro: linha faltando na face '%s'\n", faces[face]);
                fclose(arq);
                return 0;
            }

            if (strlen(linha) != 3) {
                printf("Erro: linha %d da face '%s' tem tamanho errado\n", i + 1, faces[face]);
                fclose(arq);
                return 0;
            }

            for (j = 0; j < 3; j++) {
                if (!corValida(linha[j])) {
                    printf("Erro: cor invalida '%c' na face '%s'\n", linha[j], faces[face]);
                    fclose(arq);
                    return 0;
                }
                cubo[face][i][j] = linha[j];
            }
        }
    }

    fclose(arq);
    return 1;
}

void exibirCubo() {
    int face, i, j;

    for (face = 0; face < 6; face++) {
        printf("Face %s:\n", faces[face]);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++)
                printf("%c ", cubo[face][i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    if (!lerCubo(argv[1]))
        return 1;

    printf("Cubo lido com sucesso!\n\n");
    exibirCubo();
    return 0;
}
