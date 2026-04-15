#include <stdio.h>

int main() {
    int N, X, Y;
    scanf("%d %d %d", &N, &X, &Y);

    int latas[10000] = {0};

    int horas, minutos, Z;

    // Processa os clientes com mais de 1 lata
    for (int i = 0; i < Y; i++) {
        scanf("%d:%d %d", &horas, &minutos, &Z);

        int totalMin = (horas - 7) * 60 + minutos;
        int cliente = totalMin / 3;

        latas[cliente] = Z;
    }

    // Preenche os que compraram 1 lata
    if (X != 0) {
        for (int i = 1; i <= N; i++) {
            if (latas[i] == 0 && i % X == 0) {
                latas[i] = 1;
            }
        }
    }

    int soma = 0;
    int vencedor = -1;

    for (int i = 1; i <= N; i++) {
        soma += latas[i];

        if (soma >= 50) {
            vencedor = i;
            break;
        }
    }

    if (vencedor == -1) {
        int faltam = 50 - soma;
        if (faltam == 1){
            printf("Ainda nao foram vendidas latas suficientes. Falta 1 lata.\n");
        }else{
            printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", faltam);
        }
    } else {
        int totalMin = vencedor * 3;
        int h = 7 + totalMin / 60;
        int m = totalMin % 60;

        printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d lata", 
               vencedor, h, m, latas[vencedor]);

        if (latas[vencedor] > 1) {
            printf("s");
        }

        printf(".\n");
    }

    return 0;
}