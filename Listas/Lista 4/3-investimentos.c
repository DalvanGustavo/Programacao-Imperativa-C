#include <stdio.h>

int main() {
    // Matriz 4x4 para contar quantas vezes Pedro pisou em cada coordenada
    int cidade[4][4] = {0}; 
    
    int x = 0; 
    int y = 0; 
    char passo;

    // Loop para ler exatamente 20 passos do Reypedrof
    for (int i = 0; i < 20; i++) {
        if (scanf(" %c", &passo) != 1) {
            break;
        }

        // Atualiza as coordenadas garantindo os limites da matriz (0 a 3)
        if (passo == 'c' && y > 0) y--;
        else if (passo == 'b' && y < 3) y++;
        else if (passo == 'e' && x > 0) x--;
        else if (passo == 'd' && x < 3) x++;
        
        // Adiciona +1 no local que Pedro acabou de pisar
        cidade[x][y]++;
    }

    int max_passos = -1;
    int emboscada_x = 0;
    int emboscada_y = 0;

    // Varre toda a matriz para descobrir qual coordenada teve o maior número de visitas
    for (int i = 0; i < 4; i++) {       // i = coluna (X)
        for (int j = 0; j < 4; j++) {   // j = linha (Y)
            if (cidade[i][j] > max_passos) {
                max_passos = cidade[i][j];
                emboscada_x = i;
                emboscada_y = j;
            }
        }
    }

    // Imprime o destino onde a Manuela estará esperando
    // Ajustado para ficar exatamente igual é saída esperada (sem espaço após o X:)
    printf("Coordenada X:%d, Y:%d\n", emboscada_x, emboscada_y);

    return 0;
}