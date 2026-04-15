#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para o qsort (ordem crescente)
int comparar(const void *a, const void *b)
{
    float fa = *(float *)a;
    float fb = *(float *)b;
    if (fa < fb)
        return -1;
    if (fa > fb)
        return 1;
    return 0;
}

// --- Funções de Cálculo ---

float calcularMedia(float *notas, int n)
{
    float soma = 0;
    for (int i = 0; i < n; i++)
        soma += notas[i];
    return soma / n;
}

// Função para encontrar o maior valor e seu ID
void encontrarMaior(float *notas, int n, float *valor, int *id)
{
    *valor = notas[0];
    *id = 1;
    for (int i = 1; i < n; i++)
    {
        if (notas[i] > *valor)
        {
            *valor = notas[i];
            *id = i + 1;
        }
    }
}

// Função para encontrar o menor valor e seu ID
void encontrarMenor(float *notas, int n, float *valor, int *id)
{
    *valor = notas[0];
    *id = 1;
    for (int i = 1; i < n; i++)
    {
        if (notas[i] < *valor)
        {
            *valor = notas[i];
            *id = i + 1;
        }
    }
}

// Função para contar quantos alunos estão acima da média
int contarAcimaMedia(float *notas, int n, float media)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (notas[i] > media)
            cont++;
    }
    return cont;
}

// Função para calcular a mediana
float calcularMediana(float *notas, int n)
{
    float *copia = malloc(n * sizeof(float));
    memcpy(copia, notas, n * sizeof(float));
    qsort(copia, n, sizeof(float), comparar);

    float mediana;
    if (n % 2 != 0)
    {
        mediana = copia[n / 2];
    }
    else
    {
        mediana = (copia[(n / 2) - 1] + copia[n / 2]) / 2.0;
    }

    free(copia);
    return mediana;
}

// Função para calcular a moda
void calcularModa(float *notas, int n)
{
    float *copia = malloc(n * sizeof(float));
    memcpy(copia, notas, n * sizeof(float));
    qsort(copia, n, sizeof(float), comparar);

    int max_frequencia = 0;
    int frequencia_atual = 1;
    float moda_valor = copia[0];
    int qtd_modas = 0;

    // Primeiro, descobre a maior frequência
    for (int i = 1; i <= n; i++)
    {
        if (i < n && copia[i] == copia[i - 1])
        {
            frequencia_atual++;
        }
        else
        {
            if (frequencia_atual > max_frequencia)
            {
                max_frequencia = frequencia_atual;
                moda_valor = copia[i - 1];
            }
            frequencia_atual = 1;
        }
    }

    // Agora, verifica se essa frequência é única
    frequencia_atual = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i < n && copia[i] == copia[i - 1])
        {
            frequencia_atual++;
        }
        else
        {
            if (frequencia_atual == max_frequencia)
            {
                qtd_modas++;
            }
            frequencia_atual = 1;
        }
    }

    if (qtd_modas == 1 && max_frequencia > 1)
    {
        printf("Moda: %.2f\n", moda_valor);
    }
    else
    {
        printf("Moda: Nao ha moda unica\n");
    }

    free(copia);
}

// Função para imprimir o relatório completo
void imprimirRelatorio(float *notas, int n)
{
    float media = calcularMedia(notas, n);
    float maiorV, menorV;
    int maiorID, menorID;

    encontrarMaior(notas, n, &maiorV, &maiorID);
    encontrarMenor(notas, n, &menorV, &menorID);

    printf("Media: %.2f\n", media);
    printf("Maior nota: %.2f (aluno %d)\n", maiorV, maiorID);
    printf("Menor nota: %.2f (aluno %d)\n", menorV, menorID);
    printf("Acima da media: %d\n", contarAcimaMedia(notas, n, media));
    printf("Mediana: %.2f\n", calcularMediana(notas, n));
    calcularModa(notas, n);
}

int main()
{
    int n, k;

    // Leitura inicial
    if (scanf("%d", &n) == EOF)
        return 0;
    float *notas = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
        scanf("%f", &notas[i]);

    // Primeiro Relatório
    puts("Relatorio inicial");
    imprimirRelatorio(notas, n);
    printf("\n");

    // Adição de novas notas
    scanf("%d", &k);
    if (k > 0)
    {
        notas = realloc(notas, (n + k) * sizeof(float));
        for (int i = 0; i < k; i++)
        {
            scanf("%f", &notas[n + i]);
        }
        n += k;
    }

    // Relatório Atualizado
    puts("Relatorio atualizado");
    imprimirRelatorio(notas, n);

    free(notas);
    return 0;
}