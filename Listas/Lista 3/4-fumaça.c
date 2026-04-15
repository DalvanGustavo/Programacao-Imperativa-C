#include <stdio.h>

int main() {
    int R;
    if (scanf("%d", &R) != 1) return 0;

    // Vetor para a luz de natal gigante (1000 * 60 caracteres + 1000 conectores)
    char gigante[70000]; 
    int lenG = 0; // Guarda o tamanho atual da luz gigante

    for (int k = 0; k < R; k++) {
        char S[70];
        long long int F; // Usamos long long caso F seja um número gigantesco
        
        scanf(" %s %lld", S, &F);

        // 1. Descobrir o tamanho da string S
        int lenS = 0;
        while (S[lenS] != '\0') {
            lenS++;
        }

        // 2. Aplicar os F clocks (Soma Binária)
        long long int carry = F; // O "vai um" começa com o valor de F
        
        for (int i = 0; i < lenS; i++) {
            if (carry == 0) break; // Se não tem mais o que somar, podemos parar cedo

            int bit_atual = (S[i] == 'O') ? 1 : 0; // 'O' é 1, 'X' é 0
            long long int soma = bit_atual + carry;

            // Se a soma for ímpar (1, 3, 5...), o LED fica ligado 'O'
            if (soma % 2 == 1) {
                S[i] = 'O';
            } else {
                S[i] = 'X'; // Se for par (0, 2, 4...), fica desligado 'X'
            }
            
            // O que sobra vai para o próximo LED
            carry = soma / 2; 
        }

        // Imprime o resultado do teste atual (conforme a saída exigida)
        printf("%s\n", S);

        // 3. Juntar na luz gigante do Soneca
        if (k == 0) {
            // Se for o primeiro fio, apenas copiamos para a gigante
            for (int i = 0; i < lenS; i++) {
                gigante[lenG] = S[i];
                lenG++;
            }
        } else {
            // Se não for o primeiro, precisamos analisar o conector
            char lastG = gigante[lenG - 1]; // Último led da gigante
            char firstB = S[0];             // Primeiro led do novo fio
            char conector;

            if (lenG % 2 == 0) { // Tamanho atual é PAR
                if (lastG == firstB) {
                    conector = '@';
                } else {
                    conector = '$';
                }
            } else {             // Tamanho atual é ÍMPAR
                if (lastG == firstB) {
                    conector = '#';
                } else {
                    conector = '%';
                }
            }

            // Adiciona o conector
            gigante[lenG] = conector;
            lenG++;

            // Adiciona o novo fio
            for (int i = 0; i < lenS; i++) {
                gigante[lenG] = S[i];
                lenG++;
            }
        }
    }

    // Fecha a string gigante e imprime
    gigante[lenG] = '\0';
    printf("%s\n", gigante);

    return 0;
}