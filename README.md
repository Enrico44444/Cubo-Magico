# Instruções de Execução

1. Execute `make compile run` para compilar e executar o programa.

2. Escolha a opção **1** para gerar cubos embaralhados.

3. Informe quantos cubos deseja gerar. Os arquivos serão criados na pasta `cubos_gerados`.

4. Copie um dos cubos gerados para a pasta `cubo_selecionado`. Esse será o cubo que será resolvido pelo programa.

5. Execute `make run` para iniciar o programa novamente.

6. Desta vez, escolha a opção **2** para resolver o cubo.

7. Informe o nome exato do arquivo presente na pasta `cubo_selecionado`.

8. O programa tentará resolver o cubo aplicando movimentos aleatórios até encontrar uma solução.

**EXTRA:** Ao selecionar a opção **3**, você entra no modo _Sandbox_, podendo mover um cubo selecionado manualmente.
---

# Estrutura das Pastas

* `cubo_selecionado`: pasta onde deve ser colocado o cubo que será resolvido.
* `cubos_gerados`: pasta onde os cubos gerados são armazenados.
* `include`: contém os arquivos de cabeçalho `funcoes.h` e `gerador.h`.

---

# Código

## `funcoes.c`

Contém as seguintes funções:

### `void mover_cubo(char cubo[6][3][3], int face, int sentido)`

Move o cubo utilizando as funções `rotaciona_face()` e `move_perpendiculares()`. Recebe como parâmetros o cubo, a face a ser rotacionada e o sentido da rotação.

### `void rotaciona_face(char cubo[6][3][3], int face, int sentido)`

Rotaciona apenas a face selecionada, reorganizando suas linhas e colunas. Recebe como parâmetros o cubo, a face e o sentido da rotação.

### `void move_perpendiculares(char cubo[6][3][3], int face, int sentido)`

Move as peças das faces adjacentes à face rotacionada. Recebe como parâmetros o cubo, a face e o sentido da rotação.

### `void imprime_cubo(char cubo[6][3][3])`

Imprime o cubo no terminal. Algumas faces são invertidas durante a impressão para facilitar a comparação com um cubo físico.

### `int solved(char cubo[6][3][3])`

Verifica se o cubo está resolvido.

### `int ler_cubo(char *path, char cubo[6][3][3])`

Lê um cubo previamente colocado na pasta `cubo_selecionado`.

### `void resolver_cubo(char cubo[6][3][3])`

Aplica movimentos aleatórios ao cubo até que ele seja resolvido.

---

## `gerador.c`

Contém a seguinte função:

### `void gerar_cubos(char cubo[6][3][3], int quantidade)`

Gera a quantidade de cubos informada pelo usuário na pasta `cubos_gerados`. Cada cubo é embaralhado por meio de 20 movimentos aleatórios.

---

# Makefile

### `make compile`

Compila o programa.

### `make clean`

Remove o executável e limpa as pastas `cubo_selecionado` e `cubos_gerados`.

### `make run`

Executa o arquivo `projeto_final.exe`.
