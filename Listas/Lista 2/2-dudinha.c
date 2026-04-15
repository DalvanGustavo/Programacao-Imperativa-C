#include <stdio.h>
int main(){
    int N, K, P, Q = 0, primeiro = -1;
    scanf("%d %d %d", &N, &K, &P);
    for(int i = N; i < K; i++){
        int x = i, quantidade = 0, invalido = 0;
        //loop para remover fator 2
        while (x % 2 == 0 && x > 0){
            x /= 2;
        }
        //loop para testar divisores ímpares
        for (int d = 3; d * d <= x; d += 2){
            int cont = 0;
            while (x % d == 0){
                x /= d;
                cont++;
            }
            //verificar repetição
            if (cont > 1){
                invalido = 1;
            }
            if (cont == 1){
                quantidade++;
            }
        }
        //fator restante
        if (x > 1){
            quantidade++;
        }
        //verificar se atende as condições
        if (!invalido && quantidade == P){
            if (primeiro == -1){
                primeiro = i;
            }else{
                Q++;
            }
        }
    }
    //bloco de resposta
    if (primeiro != -1){
        printf("%d %d\n", primeiro, Q);
    }else{
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }
    return 0;
}