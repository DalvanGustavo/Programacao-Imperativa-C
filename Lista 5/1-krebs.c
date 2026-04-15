#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para evoluir o ornitorrinco
char evoluir(char c)
{
    if (c == 'z')
        return 'a';
    return c + 1;
}

int main()
{
    int n;
    if (scanf("%d", &n) == EOF)
        return 0;

    // Alocação dinâmica para o array de ponteiros
    char **ornitorrincos = (char **)malloc(n * sizeof(char *));
    if (ornitorrincos == NULL)
        return 1;

    int total_chars = 0;
    for (int i = 0; i < n; i++)
    {
        char buffer[1001]; // Buffer temporário para leitura
        scanf("%s", buffer);
        int len = strlen(buffer);
        total_chars += len;

        ornitorrincos[i] = (char *)malloc((len + 1) * sizeof(char));
        if (ornitorrincos[i] == NULL)
            return 1;
        strcpy(ornitorrincos[i], buffer);
    }

    // --- ALGORITMO DE MESCLAGEM ---
    char *merged = (char *)malloc((total_chars + 1) * sizeof(char));
    if (merged == NULL)
        return 1;

    int m_idx = 0;
    int ainda_tem_char = 1;
    int offset = 0;

    while (ainda_tem_char)
    {
        ainda_tem_char = 0;
        for (int i = 0; i < n; i++)
        {
            if (offset < strlen(ornitorrincos[i]))
            {
                merged[m_idx++] = ornitorrincos[i][offset];
                ainda_tem_char = 1;
            }
        }
        offset++;
    }
    merged[m_idx] = '\0';

    // Print da primeira etapa
    printf("%s\n", merged);

    // --- ALGORITMO DE FUSÃO ---
    // Trabalharemos em uma cópia para preservar a original se necessário,
    // ou diretamente na merged se não precisarmos mais dela.
    for (int i = 0; i < (int)strlen(merged) - 1; i++)
    {
        // Se houver caracteres adjacentes iguais
        if (merged[i] == merged[i + 1])
        {
            merged[i] = evoluir(merged[i]);

            // Shift para a esquerda (remove o caractere fundido)
            for (int j = i + 1; j < (int)strlen(merged); j++)
            {
                merged[j] = merged[j + 1];
            }

            // Retrocede o índice para verificar novas fusões criadas
            i = -1; // O laço fará i++, voltando para o 0
        }
    }

    // Print da segunda etapa
    printf("%s\n", merged);

    // --- LIMPEZA DE MEMÓRIA ---
    for (int i = 0; i < n; i++)
    {
        free(ornitorrincos[i]);
    }
    free(ornitorrincos);
    free(merged);

    return 0;
}