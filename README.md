# Programação Imperativa (C)

# 📔 Diário de Bordo 

Na Lista 1, o foco principal foi o aprimoramento do uso de **estruturas de decisão (if/else)**, **operações matemáticas** e **lógica de programação** aplicada a diferentes cenários. Abaixo, um breve resumo dos problemas resolvidos:

* **Problema 1 (Calculadora de Sorte/Horóscopo):** * **O que aprendi/pratiquei:** Manipulação de múltiplas variáveis de data, uso intensivo do operador módulo (`%`) para gerar índices, e aplicação de blocos `if/else` encadeados para categorizar resultados (amor, sorte, trabalho e cor).
* **Problema 2 (Soma de Múltiplos com Inclusão-Exclusão):**
    * **O que aprendi/pratiquei:** Uso do tipo `long long` para evitar *overflow* ao lidar com números grandes. Aplicação de otimização matemática (fórmulas de PA e princípio da inclusão-exclusão) no lugar de loops (`for`/`while`) para garantir a eficiência do código.
* **Problema 3 (Investimentos da Rebeka):**
    * **O que aprendi/pratiquei:** Lógica condicional complexa e aninhada. O desafio exigiu testar múltiplos cenários de investimento em cascata, além de integrar leitura de caracteres (`char`) e uma iteração simples com arrays para verificar divisibilidade.
* **Problema 4 (Fuga do Quadrante - Mário):**
    * **O que aprendi/pratiquei:** Lógica espacial e matemática com coordenadas cartesianas. Uso da função `abs()` para calcular distâncias absolutas e controle de fluxo para definir a ordem de impressão (X primeiro ou Y primeiro) para desviar de um obstáculo (quadrante evitado).

**Reflexão geral:** Sinto que meu domínio sobre o controle de fluxo (`if/else`) e a tradução de regras matemáticas para o código em C evoluiu bastante com esta lista.



Na Lista 2, os desafios subiram de nível, focando em **laços de repetição (loops)**, **teoria dos números** e **simulação de algoritmos**. Foi o momento de colocar o `for` e o `while` para trabalhar pesado.

* **Problema 1 (Triângulo de Letras):**
    * **O que aprendi/pratiquei:** Manipulação avançada de loops aninhados para criar padrões geométricos. Trabalhei com a aritmética de `char` para imprimir sequências alfabéticas crescentes e decrescentes e utilizei lógica de preenchimento (pontos) para garantir a simetria.
* **Problema 2 (Fatores Primos e Números Especiais):**
    * **O que aprendi/pratiquei:** Implementação de um algoritmo de fatoração. Pratiquei como decompor um número, verificar se ele é "livre de quadrados" (sem fatores repetidos) e contar a quantidade exata de fatores primos distintos dentro de um intervalo.
* **Problema 3 (Canais de Fibonacci e VIP):**
    * **O que aprendi/pratiquei:** Simulação de sequências dinâmicas (estilo Fibonacci) para encontrar o valor mais próximo de um alvo $x$. Além disso, pratiquei a extração de algarismos de um número usando `% 10` e `/ 10` para validar condições extras.
* **Problema 4 (Caminho de Pontos):**
    * **O que aprendi/pratiquei:** Simulação de coordenadas e "desenho" no terminal. O desafio foi gerenciar o estado da "caneta" (posição da coluna e se houve descida de linha) para imprimir espaços e pontos corretamente de acordo com as direções (Direita, Baixo, Esquerda).

**Reflexão geral:** O uso de loops aninhados e a necessidade de controlar o estado das variáveis a cada iteração foram os pontos mais exigentes. A depuração (debug) de lógica de repetição tornou-se uma ferramenta essencial aqui.



Na Lista 3, o foco saiu das variáveis simples e entrou na manipulação de **coleções de dados (Arrays)** e **cadeias de caracteres (Strings)**. Os desafios exigiram maior cuidado com índices e lógica de memória.

---

### 🚀 O que aprendi/pratiquei:

* **Problema 1 (Segmentos Decrescentes):**
    * **Lógica:** Pratiquei a busca por padrões dentro de um vetor, utilizando variáveis de controle para "salvar" o melhor estado (início e tamanho da maior sequência) enquanto o laço percorre os dados.
    * **Conceito chave:** Algoritmos de busca em subarranjos.

* **Problema 2 (Simulação de Vendas e Tempo):**
    * **Lógica:** Trabalhei com mapeamento de dados onde o índice do vetor representava um ID (cliente). Aprendi a converter formatos de tempo (HH:MM) para uma escala linear de minutos para facilitar cálculos de intervalos.
    * **Conceito chave:** Mapeamento de índices e normalização de tempo.

* **Problema 3 (Busca de Anagramas em Frases):**
    * **Lógica:** Este foi um salto em manipulação de `Strings`. Usei a técnica de **Vetor de Frequência** (contagem de letras de 'a' a 'z') para comparar palavras sem precisar ordená-las. Também pratiquei a filtragem de caracteres não alfabéticos.
    * **Conceito chave:** `scanf` com máscaras especiais (`%[^\n]`), tabela ASCII e vetores de contagem.

* **Problema 4 (LEDs Binários e Conectores):**
    * **Lógica:** Implementei um **somador binário manual** aplicado a uma string, tratando caracteres como bits e gerenciando o "vai um" (*carry*). Além disso, manipulei uma string gigante com lógica de concatenação baseada em regras de paridade.
    * **Conceito chave:** Aritmética binária em strings e manipulação de grandes buffers de texto.

---

### 💡 Reflexão Geral:
A maior dificuldade desta lista não foi apenas a lógica matemática, mas o **gerenciamento dos índices**. Um pequeno erro de `i + 1` ou esquecer o `\0` no final de uma string pode quebrar o código inteiro. Sinto que minha atenção aos detalhes e minha habilidade de debugar vetores melhoraram significativamente.



Na Lista 4, o nível de abstração subiu consideravelmente. O foco saiu de listas simples e entrou no domínio das **Matrizes (Grids)**, explorando como navegar em duas dimensões e como implementar algoritmos clássicos de busca e simulação.

---

### 🚀 O que aprendi/pratiquei:

* **Problema 1 (Labirinto com BFS):**
    * **Lógica:** Implementação do algoritmo **BFS (Breadth-First Search)** para encontrar o caminho mais curto em um mapa. Foi necessário gerenciar uma fila manual e controlar estados de "visitado" para evitar loops infinitos.
    * **Conceito chave:** Busca em Largura, Filas (Queues) e Alocação Dinâmica de matrizes (`malloc`/`free`).

* **Problema 2 (Simulação de Escoamento com Recursão):**
    * **Lógica:** Uso de **Recursão** para simular o caminho físico de uma gota de água. O código decide para onde a água "escorre" (baixo, esquerda ou direita) dependendo dos obstáculos (`#`).
    * **Conceito chave:** Funções recursivas (DFS - Depth-First Search) e lógica de física simplificada em matrizes.

* **Problema 3 (Rastreamento de Movimento):**
    * **Lógica:** Mapeamento de coordenadas (X, Y) em uma matriz 4x4. O objetivo foi transformar comandos de direção (`c`, `b`, `e`, `d`) em incrementos de índices e usar a própria matriz como um **contador de frequência** de visitas.
    * **Conceito chave:** Manipulação de índices de matriz e busca de valor máximo dentro de um grid.

* **Problema 4 (Decoração de Praça / Lógica de Vizinhança):**
    * **Lógica:** Percorrimento de matriz com análise de vizinhos. Para cada poste (`P`), o algoritmo aplica regras de preenchimento ao redor (cruz vs. diagonal), lidando com **prioridades de sobrescrita**.
    * **Conceito chave:** Varredura de matriz e vetores de direção (offset) para acessar elementos adjacentes.

---

### 💡 Reflexão Geral:
Trabalhar com matrizes me mostrou como a organização dos dados facilita a resolução de problemas complexos. A parte mais desafiadora foi a **Alocação Dinâmica** no Problema 1 — entender que cada linha precisa ser alocada individualmente e liberada na ordem inversa — e o controle de limites para evitar o erro de *segmentation fault* ao acessar vizinhos fora do mapa. Utilizei I.A para completar tarefas, e, pela recomendação da I.A, conheci os ponteiros.



Na Lista 5, o foco foi dominar o ciclo de vida da memória em C: **Alocar (`malloc`), Realocar (`realloc`) e Liberar (`free`)**. Deixamos de depender de tamanhos pré-definidos para criar programas que se adaptam ao volume de dados em tempo real.

---

### 🚀 O que aprendi/pratiquei:

* **Problema 1 (Evolução de Ornitorrincos):**
    * **Lógica:** Manipulação complexa de strings usando um array de ponteiros (`char **`). Implementei dois algoritmos: a **mesclagem** (intercalar caracteres de várias strings) e a **fusão** (uma lógica recursiva/iterativa onde letras iguais adjacentes "evoluem" para a próxima letra do alfabeto).
    * **Conceito chave:** Ponteiros para ponteiros, aritmética de ponteiros e o uso de `malloc` para strings de tamanhos variados.

* **Problema 2 (Relatório Estatístico de Notas):**
    * **Lógica:** Criação de um sistema modular para calcular estatísticas (Média, Mediana, Moda, Maior e Menor). A grande sacada foi o uso do `realloc` para expandir o vetor de notas quando novos alunos eram adicionados após o relatório inicial.
    * **Conceito chave:** Ordenação com `qsort`, lógica de frequência para moda e redimensionamento dinâmico de memória.

* **Problema 3 (Separador Ímpar/Par com Expansão Manual):**
    * **Lógica:** Implementação de um padrão clássico da computação: o **vetor dinâmico com crescimento exponencial**. Em vez de alocar um espaço gigante de uma vez, os vetores começam pequenos e dobram de capacidade (`capacidade * 2`) sempre que ficam cheios.
    * **Conceito chave:** Leitura até o fim do arquivo (`EOF`) e gerenciamento eficiente de capacidade de memória para evitar múltiplas chamadas caras ao sistema operacional.

---

### 💡 Reflexão Geral:
A alocação dinâmica é, sem dúvida, um divisor de águas. É onde o programador C ganha controle total (e responsabilidade total) sobre o hardware. O maior aprendizado aqui foi a disciplina: para cada `malloc`, deve haver um `free`. O uso do `realloc` me mostrou na prática como estruturas de dados famosas de outras linguagens funcionam por baixo dos panos.


**Em todas as listas utilizei I.A para tirar dúvidas, principalmente sobre quais comandos usar para uma determinada tarefa expecífica**
