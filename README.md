# Batalha Naval com Habilidades em C

Programa desenvolvido em linguagem C com o objetivo de simular um **tabuleiro de Batalha Naval** no console, incluindo a disposição de navios e a aplicação de **habilidades especiais** com diferentes áreas de efeito.

Este projeto tem foco didático no uso de **matrizes**, **loops aninhados**, **condicionais** e **lógica de sobreposição de estruturas**, explorando a manipulação de dados bidimensionais de forma organizada e visual.

## Elementos do tabuleiro

O programa trabalha com um tabuleiro 10x10 onde são representados:

- Água (`~`)
- Navios (`N`)
- Áreas de efeito de habilidades (`*`)

Os navios são posicionados em diferentes orientações:

- Horizontal
- Vertical
- Diagonal principal
- Diagonal secundária

## Habilidades implementadas

O projeto implementa três habilidades com matrizes próprias de efeito (5x5):

- **Cone** (apontado para baixo)
- **Cruz**
- **Octaedro** (formato de losango)

Cada habilidade é representada por uma matriz contendo valores:

- `0` → Área não afetada
- `1` → Área afetada

Essas matrizes são posteriormente **sobrepostas ao tabuleiro principal** a partir de um ponto de origem definido no código.

## Funcionalidades implementadas

O programa realiza:

- Inicialização do tabuleiro com água
- Posicionamento de navios em múltiplas direções
- Criação dinâmica das matrizes de habilidade utilizando cálculos lógicos
- Definição de pontos de origem para cada habilidade
- Sobreposição das habilidades no tabuleiro respeitando os limites
- Exibição organizada do tabuleiro com coordenadas no terminal

## Regras de sobreposição

- As habilidades só afetam posições que estejam com água
- Navios não são sobrescritos pelas habilidades
- Cada habilidade possui um ponto central que define sua posição no tabuleiro

## Conceitos de C aplicados

Este projeto utiliza:

- Matrizes bidimensionais
- Loops aninhados (`for`)
- Condicionais (`if`)
- Cálculos com coordenadas
- Manipulação de índices em matrizes
- Organização visual no terminal
- Boas práticas de identação e legibilidade

## Objetivo didático

O foco do projeto é praticar e fixar:

- Manipulação de matrizes
- Raciocínio espacial e lógico
- Uso eficiente de loops aninhados
- Sobreposição de estruturas em memória
- Clareza na visualização de dados no console

## Como compilar e executar (Code::Blocks)

- Abra o Code::Blocks
- Clique em **File → Open**
- Selecione o arquivo `.c`
- Clique em **Build and Run** (ou pressione `F9`)

O programa será compilado e executado automaticamente no console.

### Projeto desenvolvido e testado utilizando a IDE Code::Blocks.
