#include <stdio.h>

int main(){
    char letra;
    scanf("%c", &letra);
    int l = letra - 'A';
    //loop para impressão do triângulo
    for(int i = 0; i <= l; i++)
    {
        // loop para acrescentar os pontos no inicio de cada linha do triângulo, antes da linha final
        for(int j = 0; j < l - i; j++)
            printf(".");
        
        //loop para escrever as letras em ordem crescente
        for(int j = 0; j <= i; j++)
            printf("%c", 'A' + j);
        
        //loop para escrever as letras em ordem decrescente
        for(int j = i - 1; j >= 0; j--)
            printf("%c", 'A' + j);
        
        //loop para acresncentar os pontos no final de cada linha do triângulo, antes da última linha
        for (int j = 0; j < l - i; j++)
            printf(".");
        
        printf("\n");
    }
    return 0;
}