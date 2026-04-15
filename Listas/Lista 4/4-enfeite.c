#include <stdio.h>

int main() {
    int m, n;
    
    // Lê as dimensões da matriz
    if (scanf("%d %d", &m, &n) != 2) return 0;

    char praca[105][105];
    
    // Lê o estado inicial da praça
    for (int i = 0; i < m; i++) {
        scanf("%s", praca[i]);
    }

    // Percorre toda a matriz procurando pelos postes ('P')
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            // Quando encontra um poste, aplica os enfeites ao redor
            if (praca[i][j] == 'P') {
                
                // 1. Enfeites em cruz (+) -> Cima, Baixo, Esquerda, Direita
                int dx_cruz[] = {-1, 1, 0, 0};
                int dy_cruz[] = {0, 0, -1, 1};
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx_cruz[k];
                    int nj = j + dy_cruz[k];
                    
                    // Verifica se a posição vizinha está dentro dos limites da matriz
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        // O sinal '+' tem prioridade sobre '-' e 'x'. 
                        // Só não pode sobrescrever outro poste 'P'.
                        if (praca[ni][nj] != 'P') {
                            praca[ni][nj] = '+';
                        }
                    }
                }

                // 2. Enfeites nas diagonais (x) -> Cima-Esq, Cima-Dir, Baixo-Esq, Baixo-Dir
                int dx_diag[] = {-1, -1, 1, 1};
                int dy_diag[] = {-1, 1, -1, 1};
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx_diag[k];
                    int nj = j + dy_diag[k];
                    
                    // Verifica limites da matriz
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        // O sinal 'x' tem a menor prioridade dos enfeites.
                        // Só pode ser colocado se o espaço estiver totalmente vazio ('-').
                        if (praca[ni][nj] == '-') {
                            praca[ni][nj] = 'x';
                        }
                    }
                }
            }
        }
    }

    // Imprime o resultado final da praça decorada
    for (int i = 0; i < m; i++) {
        printf("%s\n", praca[i]);
    }

    return 0;
}