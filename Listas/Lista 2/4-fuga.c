#include <stdio.h>

int main(){

    int qtdInstrucoes, qtdPassos, coluna = 0, desceu = 0;
    char direcao;

    scanf("%d", &qtdInstrucoes);

    for(int i = 0; i < qtdInstrucoes; i++){
        scanf("%d %c", &qtdPassos, &direcao);

        //direita
        if(direcao == 'D'){
            if(desceu == 1){
                for (int k = 1; k < coluna; k++)
                {
                    printf(" ");
                }
                printf(".");
            }
            for(int j = 0; j < qtdPassos; j++){
                printf(".");
            }
            coluna += qtdPassos;
            desceu = 0;
        }

        //baixo
        else if (direcao == 'B'){
            desceu = 1;
            while (qtdPassos > 0)
            {
                printf("\n");
                if(qtdPassos > 1 || i == qtdInstrucoes - 1){
                    for(int k = 1; k < coluna; k++){
                        printf(" ");
                    }
                    printf(".");
                }

                qtdPassos--;
            }
        }

        //esquerda
        else if (direcao == 'E'){
            int fimK = coluna - qtdPassos;
            for (int k = 1; k < fimK; k++)
            {
                printf(" ");
            }
            for (int j = 0; j < qtdPassos+1; j++)
            {
                printf(".");
            }
            coluna -= qtdPassos;
            desceu = 0;
        }
        
    }

    return 0;
}