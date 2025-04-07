#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Utilizando estrutura para facilitar o agrupamento de dados

    typedef struct {
        char estado[3];
        char codigo[10];
        char nomeCidade[50];
        int populacao;
        float area;
        float pib;
        int pontosTuristicos;
        float densidadePopulacional;
        float pibPerCapita;
    } Carta;

    Carta carta1, carta2;

    // Cadastro das Cartas:
    // Solicitando ao usuário que insira os dados das cidades

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculo de Densidade Populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Comparação de Cartas:
    // Comparando um atributo fixo (exemplo: densidade populacional - menor valor vence)

    printf("\n=== Comparação de Cartas (Atributo: Densidade Populacional - menor vence) ===\n");
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);

    // Exibição dos Resultados:
    // Mostrando qual carta venceu com base na densidade populacional

    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
