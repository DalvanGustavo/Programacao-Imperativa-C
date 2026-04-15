#include <stdio.h>

#define MAX 1005

char parede[MAX][MAX];
int m, n;

// Função recursiva para simular o caminho da água
void simular_gota(int r, int c) {
    // Marca a posi��o atual por onde a água passou (usando 'o' minúsculo)
    parede[r][c] = 'o';

    // Verifica se a gota não atingiu o chão (se ainda pode olhar a próxima linha)
    if (r + 1 < m) {
        
        // Se a água atingiu uma prateleira na linha de baixo
        if (parede[r + 1][c] == '#') {
            
            // Tenta escorrer para a esquerda
            if (c - 1 >= 0 && parede[r][c - 1] == '.') {
                simular_gota(r, c - 1);
            }
            
            // Tenta escorrer para a direita
            if (c + 1 < n && parede[r][c + 1] == '.') {
                simular_gota(r, c + 1);
            }
            
        } 
        // Se o espaço abaixo for vazio, continua a queda livre
        else if (parede[r + 1][c] == '.') {
            simular_gota(r + 1, c);
        }
    }
}

int main() {
    // Lê as dimensões da matriz (altura e largura)
    if (scanf("%d %d", &m, &n) != 2) return 0;
    
    // Lê a configuração inicial da parede
    for (int i = 0; i < m; i++) {
        scanf("%s", parede[i]);
    }

    int start_r = -1, start_c = -1;
    
    // Procura as coordenadas do ponto de origem da goteira 
    // (agora aceitando tanto 'O' maiúsculo quanto 'o' minúsculo para evitar bugs)
    for (int i = 0; i < m && start_r == -1; i++) {
        for (int j = 0; j < n; j++) {
            if (parede[i][j] == 'O' || parede[i][j] == 'o') {
                start_r = i;
                start_c = j;
                break; // Achou a goteira, sai da busca
            }
        }
    }

    // Inicia a simulação a partir do local da goteira
    if (start_r != -1) {
        simular_gota(start_r, start_c);
    }

    // Imprime o resultado final da matriz com o trajeto atualizado da água
    for (int i = 0; i < m; i++) {
        printf("%s\n", parede[i]);
    }
    return 0;
}