#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar cada posição e a distância percorrida até ela
typedef struct {
    int r;    // linha (row)
    int c;    // coluna (column)
    int dist; // distância da origem
} Node;

int main() {
    int linhas, colunas;
    
    // Lê o formato "linhasxcolunas" (ex: 5x5)
    if (scanf("%dx%d", &linhas, &colunas) != 2) {
        return 1;
    }

    // Alocação dinâmica da matriz (mapa) e matriz de visitados
    char **mapa = malloc(linhas * sizeof(char *));
    int **visitado = malloc(linhas * sizeof(int *));
    
    int inicio_r = -1, inicio_c = -1;

    for (int i = 0; i < linhas; i++) {
        mapa[i] = malloc(colunas * sizeof(char));
        visitado[i] = calloc(colunas, sizeof(int)); // calloc já zera a matriz
        
        for (int j = 0; j < colunas; j++) {
            // " %c" ignora espaços em branco e quebras de linha entre os caracteres
            scanf(" %c", &mapa[i][j]);
            
            // Registra onde Rebeka está
            if (mapa[i][j] == 'o') {
                inicio_r = i;
                inicio_c = j;
            }
        }
    }

    // Fila para a Busca em Largura (BFS)
    Node *fila = malloc(linhas * colunas * sizeof(Node));
    int inicio_fila = 0;
    int fim_fila = 0;

    // Adiciona a posição inicial na fila
    fila[fim_fila++] = (Node){inicio_r, inicio_c, 0};
    visitado[inicio_r][inicio_c] = 1;

    // Vetores de direção: Cima, Baixo, Esquerda, Direita
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    int distancia_final = -1; // -1 indica que ainda não achou a saída

    // Execu��o do Algoritmo BFS
    while (inicio_fila < fim_fila) {
        Node atual = fila[inicio_fila++];

        // Se encontrou a saída
        if (mapa[atual.r][atual.c] == 'd') {
            distancia_final = atual.dist;
            break;
        }

        // Tenta se mover para os 4 lados
        for (int i = 0; i < 4; i++) {
            int nova_linha = atual.r + dr[i];
            int nova_coluna = atual.c + dc[i];

            // Verifica se a nova posição é válida (dentro do mapa, não é parede e não foi visitada)
            if (nova_linha >= 0 && nova_linha < linhas && 
                nova_coluna >= 0 && nova_coluna < colunas && 
                mapa[nova_linha][nova_coluna] != '#' && 
                !visitado[nova_linha][nova_coluna]) {
                
                // Marca como visitado e coloca na fila
                visitado[nova_linha][nova_coluna] = 1;
                fila[fim_fila++] = (Node){nova_linha, nova_coluna, atual.dist + 1};
            }
        }
    }

    // Verifica o resultado da fuga e imprime a mensagem correta
    if (distancia_final != -1) {
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", distancia_final);
    } else {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
        free(visitado[i]);
    }
    free(mapa);
    free(visitado);
    free(fila);

    return 0;
}