#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Alocação de um tamanho inicial pequeno para os vetores
    int capacidade_impar = 10, capacidade_par = 10;
    int *impar = malloc(capacidade_impar * sizeof(int));
    int *par = malloc(capacidade_par * sizeof(int));
    int p = 0, im = 0;
    int num;

    // Verificação de segurança da alocação
    if (impar == NULL || par == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    // ler até o End Of File (EOF)
    while (scanf("%d", &num) != EOF)
    {
        if (num % 2 != 0)
        { // Se for Ímpar
            if (im >= capacidade_impar)
            {
                capacidade_impar *= 2; // dobrar a capacidade
                impar = realloc(impar, capacidade_impar * sizeof(int));
            }
            impar[im] = num;
            im++;
        }
        else
        { // Se for Par
            if (p >= capacidade_par)
            {
                capacidade_par *= 2; // dobrar a capacidade
                par = realloc(par, capacidade_par * sizeof(int));
            }
            par[p] = num;
            p++;
        }
    }

    // Saída dos dados na ordem exata solicitada
    printf("Mais um bom dia de trabalho!\n");

    // Primeiro os Ímpares (um por linha)
    for (int j = 0; j < im; j++)
    {
        printf("%d\n", impar[j]);
    }

    // Depois os Pares (um por linha)
    for (int j = 0; j < p; j++)
    {
        printf("%d\n", par[j]);
    }

    // Mensagem final
    printf("Vou visitar esses lugares de novo... algum dia.\n");

    // Liberação da memória alocada dinamicamente
    free(impar);
    free(par);

    return 0;
}