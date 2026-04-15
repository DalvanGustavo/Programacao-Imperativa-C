#include <stdio.h>

int main() {
    int d, px, py, pz;
    if (scanf("%d %d %d %d", &d, &px, &py, &pz) != 4) return 0;

    int a, b, c, s;
    int invest = -1;
    int final_money = 3;
    int desafio_res = 0;

    // Testando Investimento 0
    if ((d * px) % 100 == 0 && (d * py) % 100 == 0 && (d * pz) % 100 == 0) {
        int ta = (d * px) / 100;
        int tb = (d * py) / 100;
        int tc = (d * pz) / 100;
        int ts = d - (ta + tb + tc);
        a = ta; b = tb; c = tc; s = ts;
        invest = 0;
    }

    // Testando Investimento 1
    if (invest == -1 && ((d + 1) * px) % 100 == 0 && ((d + 1) * py) % 100 == 0 && ((d + 1) * pz) % 100 == 0) {
        int ta = ((d + 1) * px) / 100;
        int tb = ((d + 1) * py) / 100;
        int tc = ((d + 1) * pz) / 100;
        int ts = (d + 1) - (ta + tb + tc);
        if (ts >= 2) { 
            a = ta; b = tb; c = tc; s = ts;
            invest = 1;
        }
    }

    // Testando Investimento 2
    if (invest == -1 && ((d + 2) * px) % 100 == 0 && ((d + 2) * py) % 100 == 0 && ((d + 2) * pz) % 100 == 0) {
        int ta = ((d + 2) * px) / 100;
        int tb = ((d + 2) * py) / 100;
        int tc = ((d + 2) * pz) / 100;
        int ts = (d + 2) - (ta + tb + tc);
        if (ts >= 3) {
            char L1, L2, L3;
            scanf(" %c %c %c", &L1, &L2, &L3);
            desafio_res = (L1 - 96) + (L2 - 96) + (L3 - 96);
            a = ta; b = tb; c = tc; s = ts;
            invest = 2;
        }
    }

    // Testando Investimento 3
    if (invest == -1 && ((d + 3) * px) % 100 == 0 && ((d + 3) * py) % 100 == 0 && ((d + 3) * pz) % 100 == 0) {
        int ta = ((d + 3) * px) / 100;
        int tb = ((d + 3) * py) / 100;
        int tc = ((d + 3) * pz) / 100;
        int ts = (d + 3) - (ta + tb + tc);
        if (ts >= 4) {
            int i[3];
            scanf("%d %d %d", &i[0], &i[1], &i[2]);
            int encontrou_divisivel = 0;
            int soma_local = 0;
            
            for(int j = 0; j < 3; j++) {
                if (i[j] % 3 == 0) {
                    soma_local += (i[j] / 3);
                    encontrou_divisivel = 1;
                }
            }
            
            if (encontrou_divisivel) {
                desafio_res = soma_local;
                a = ta; b = tb; c = tc; s = ts;
                invest = 3;
            }
        }
    }

    // Sa�da de Resultados
    if (invest != -1) {
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", a, b, c);
        if (invest == 2 || invest == 3) {
            printf("%d\n", desafio_res);
        }
        final_money = 3 - invest + s;
    } else {
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
        final_money = 3;
    }

    if (final_money >= 7) {
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    } else {
        printf("E parece que Rebeka vai ter que voltar andando...\n");
    }

    return 0;
}