#include <stdio.h>

int main()
{
    int x, canais, canalVencedor, minutoVencedor, menorDistancia = 9999999, vip = 0, termoVencedor = 0;
    scanf("%d %d", &x, &canais);
    for(int i = 1; i <= canais; i++){
        int num1, num2, distanciaAtual;
        scanf("%d %d", &num1, &num2);
        // 1. Testando o num1 (Minuto 1)
        if (x > num1)
            distanciaAtual = x - num1;
        else
            distanciaAtual = num1 - x;

        if (distanciaAtual < menorDistancia)
        {
            menorDistancia = distanciaAtual;
            canalVencedor = i;
            minutoVencedor = 1;
            termoVencedor = num1;
        }

        // 2. Testando o num2 (Minuto 2)
        if (x > num2)
            distanciaAtual = x - num2;
        else
            distanciaAtual = num2 - x;

        if (distanciaAtual < menorDistancia)
        {
            menorDistancia = distanciaAtual;
            canalVencedor = i;
            minutoVencedor = 2;
            termoVencedor = num2;
        }
        int minutoAtual = 3;
        int prox = num1 + num2;
        while (num2 <= x || prox <= x)
        {
            if(x > prox){
                distanciaAtual = x - prox;
            }else{
                distanciaAtual = prox - x;
            }
            if(distanciaAtual < menorDistancia){
                menorDistancia = distanciaAtual;
                canalVencedor = i;
                minutoVencedor = minutoAtual;
                termoVencedor = prox;
            }
            num1 = num2;
            num2 = prox;
            prox = num1 + num2;
            minutoAtual++;
        }
        
    }
    int somaAlgarismos = 0;
    while (termoVencedor > 0)
    {

        somaAlgarismos += termoVencedor % 10;
        termoVencedor = termoVencedor / 10;
    }
    if(somaAlgarismos > 10) vip = 1;
    if (vip == 1)
    {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canalVencedor, minutoVencedor);
    }
    else
    {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", canalVencedor, minutoVencedor);
    }
    return 0;
}