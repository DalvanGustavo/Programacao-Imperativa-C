#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y, c;
    if (scanf("%d %d %d", &x, &y, &c) != 3)
        return 0;

    int q = 0;
    if (x > 0 && y > 0)
        q = 1;
    else if (x < 0 && y > 0)
        q = 2;
    else if (x < 0 && y < 0)
        q = 3;
    else if (x > 0 && y < 0)
        q = 4;

    if (q == 0){
        printf("caminhada invalida\n");
        return 0;
    }

    // Identificar quadrante diagonal
    int q_dest = (q + 2 > 4) ? q - 2 : q + 2;
    int destX, destY;

    if (q_dest == 1){
        destX = 1;
        destY = 1;
    }else if (q_dest == 2){
        destX = -1;
        destY = 1;
    }else if (q_dest == 3){
        destX = -1;
        destY = -1;
    }else{
        destX = 1;
        destY = -1;
    }

    int passosX = abs(x - destX);
    int passosY = abs(y - destY);

    // LÓGICA CORRIGIDA:
    // Para evitar o quadrante 'c', Mário deve passar pelo outro vizinho.

    // Casos onde ele DEVE começar por Y para evitar 'c'
    if ((q == 1 && c == 2) || (q == 2 && c == 1) || (q == 3 && c == 4) || (q == 4 && c == 3)){
        printf("%d passos em y e %d passos em x\n", passosY, passosX);
    }
    // Casos onde ele DEVE começar por X para evitar 'c'
    else if ((q == 1 && c == 4) || (q == 2 && c == 3) || (q == 3 && c == 2) || (q == 4 && c == 1)){
        printf("%d passos em x e %d passos em y\n", passosX, passosY);
    }else{
        printf("caminhada invalida\n");
    }

    return 0;
}