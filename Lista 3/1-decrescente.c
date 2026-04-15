#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);

        int v[100];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &v[i]);
        }
        int inicioAtual = 0, tamanhoAtual = 1;
        int inicioMaior = 0, tamanhoMaior = 1;

        for (int i = 0; i < N - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                tamanhoAtual++;
            }
            else
            {
                if (tamanhoAtual > tamanhoMaior)
                {
                    tamanhoMaior = tamanhoAtual;
                    inicioMaior = inicioAtual;
                }
                inicioAtual = i + 1;
                tamanhoAtual = 1;
            }
        }
        // Verifica �ltima sequ�ncia
        if (tamanhoAtual > tamanhoMaior)
        {
            tamanhoMaior = tamanhoAtual;
            inicioMaior = inicioAtual;
        }

        // Sa�da
        if (tamanhoMaior == 1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", tamanhoMaior);
            for (int i = 0; i < tamanhoMaior; i++)
            {
                printf("%d ", v[inicioMaior + i]);
            }
            printf("\n");
        };
    }

    return 0;
}