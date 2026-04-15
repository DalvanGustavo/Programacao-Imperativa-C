#include <stdio.h>

int main(){
    long long N, A, B, somaTotal, somaA, somaB, somaAB, qtdA, qtdB, qtdAB, mmc, somaFinal;

    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);
    somaTotal = N * (N + 1) / 2;

    // MMC (como A e B são primos)
    mmc = A * B;

    // quantidade de múltiplos
    qtdA = N / A;
    qtdB = N / B;
    qtdAB = N / mmc;

    // soma dos múltiplos
    somaA = A * qtdA * (qtdA + 1) / 2;
    somaB = B * qtdB * (qtdB + 1) / 2;
    somaAB = mmc * qtdAB * (qtdAB + 1) / 2;

    // inclusão-exclusão
    somaFinal = somaTotal - somaA - somaB + somaAB;

    printf("%lld", somaFinal);

    if (somaFinal % 2 == 0){
        printf("\nLá ele!!!");
    }else{
        printf("\nOpa xupenio AULAS...");
    }

    return 0;
}