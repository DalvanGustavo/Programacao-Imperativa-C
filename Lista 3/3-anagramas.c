#include <stdio.h>

int main()
{
    char s[101];
    int total_pares = 0;

    // Lê a string inteira, permitindo espaços
    scanf(" %[^\n]", s);

    int i = 0;

    // Laço externo: Procura a Palavra A
    while (s[i] != '\0')
    {
        // Pula caracteres que não sejam letras (espaços, pontuação, etc)
        while (s[i] != '\0' && !((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
        {
            i++;
        }

        // Se chegou ao fim da string, encerra a busca
        if (s[i] == '\0')
            break;

        int inicioA = i; // Marca o início da Palavra A

        // Avança até o fim da Palavra A
        while (s[i] != '\0' && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
        {
            i++;
        }
        int fimA = i - 1; // Marca o fim da Palavra A

        // Laço interno: Procura a Palavra B (começando logo após a Palavra A)
        int j = i;
        while (s[j] != '\0')
        {
            // Pula caracteres que não sejam letras
            while (s[j] != '\0' && !((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')))
            {
                j++;
            }

            if (s[j] == '\0')
                break;

            int inicioB = j; // Marca o início da Palavra B

            // Avança até o fim da Palavra B
            while (s[j] != '\0' && ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')))
            {
                j++;
            }
            int fimB = j - 1; // Marca o fim da Palavra B

            // Calcula os tamanhos das duas palavras encontradas
            int tamA = fimA - inicioA + 1;
            int tamB = fimB - inicioB + 1;

            // Só podem ser anagramas se tiverem o mesmo tamanho
            if (tamA == tamB)
            {
                int contagem[26] = {0}; // Vetor para as 26 letras do alfabeto

                // Conta as letras das duas palavras ao mesmo tempo
                for (int k = 0; k < tamA; k++)
                {
                    char cA = s[inicioA + k];
                    char cB = s[inicioB + k];

                    // Converte para minúsculo somando 32 (tabela ASCII)
                    if (cA >= 'A' && cA <= 'Z')
                        cA += 32;
                    if (cB >= 'A' && cB <= 'Z')
                        cB += 32;

                    // Incrementa para a Palavra A e decrementa para a Palavra B
                    contagem[cA - 'a']++;
                    contagem[cB - 'a']--;
                }

                // Verifica se o vetor zerou (confirmando o anagrama)
                int eh_anagrama = 1;
                for (int k = 0; k < 26; k++)
                {
                    if (contagem[k] != 0)
                    {
                        eh_anagrama = 0;
                        break;
                    }
                }

                // Se for anagrama, imprime as palavras
                if (eh_anagrama == 1)
                {
                    if (total_pares == 0)
                    {
                        // Imprime o cabeçalho apenas na primeira vez que achar um par
                        printf("Pares de anagramas encontrados:\n");
                    }

                    // Imprime a Palavra A caractere por caractere
                    for (int k = inicioA; k <= fimA; k++)
                    {
                        printf("%c", s[k]);
                    }

                    printf(" e ");

                    // Imprime a Palavra B caractere por caractere
                    for (int k = inicioB; k <= fimB; k++)
                    {
                        printf("%c", s[k]);
                    }
                    printf("\n");

                    total_pares++;
                }
            }
        }
    }

    // Saída final conforme exigido pelo problema
    if (total_pares > 0)
    {
        printf("\nTotal de pares: %d\n", total_pares);
    }
    else
    {
        printf("Nao existem anagramas na frase.\n");
    }

    return 0;
}